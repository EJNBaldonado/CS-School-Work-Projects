package edu.ucr.cs.cs167.ebald009

import edu.ucr.cs.bdlab.beast.cg.SpatialJoinAlgorithms.{ESJDistributedAlgorithm, ESJPredicate}
import edu.ucr.cs.bdlab.beast.geolite.{Feature, IFeature}
import org.apache.spark.SparkConf
import org.apache.spark.rdd.RDD
import org.apache.spark.sql.SparkSession
import org.apache.spark.sql.types.{StringType, StructField, StructType}
import org.locationtech.jts.geom.{Envelope, GeometryFactory}

import edu.ucr.cs.bdlab.beast.geolite.{Feature, IFeature}
import org.apache.spark.SparkConf
import org.apache.spark.beast.SparkSQLRegistration
import org.apache.spark.rdd.RDD
import org.apache.spark.sql.{DataFrame, SaveMode, SparkSession}

import scala.collection.Map

/**
 * Scala examples for Beast
 */
object BeastScala {
  def main(args: Array[String]): Unit = {
    // Initialize Spark context

    val conf = new SparkConf().setAppName("Beast Example")
    // Set Spark master to local if not already set
    if (!conf.contains("spark.master"))
      conf.setMaster("local[*]")

    val spark: SparkSession.Builder = SparkSession.builder().config(conf)

    val sparkSession: SparkSession = spark.getOrCreate()
    val sparkContext = sparkSession.sparkContext
    SparkSQLRegistration.registerUDT
    SparkSQLRegistration.registerUDF(sparkSession)

    val operation: String = args(0)
    val inputFile: String = args(1)
    try {
      // Import Beast features
      import edu.ucr.cs.bdlab.beast._
      val t1 = System.nanoTime()
      var validOperation = true

      operation match {
        case "data-prep" =>
          val outputFile: String = args(2)
          val wildfireDF = sparkSession.read.format("csv")
            .option("sep", "\t")
            .option("inferSchema", "true")
            .option("header", "true")
            .load(inputFile)
          val wildfireRDD: SpatialRDD = wildfireDF.selectExpr("x", "y", "acq_date", "double(split(frp,',')[0]) AS frp", "acq_time", "ST_CreatePoint(x,y) AS geometry").toSpatialRDD
          val countiesRDD: SpatialRDD = sparkContext.shapefile("tl_2018_us_county.zip")
          val wildfireCountyRDD: RDD[(IFeature, IFeature)] = wildfireRDD.spatialJoin(countiesRDD)
          val wildfireCounty: DataFrame = wildfireCountyRDD.map({ case (wildfire, county) => Feature.append(wildfire, county.getAs[String]("GEOID"), "County") })
            .toDataFrame(sparkSession)
          val convertedDF: DataFrame = wildfireCounty.selectExpr("x", "y", "acq_date", "frp", "acq_time", "County").drop("geometry")
          convertedDF.write.mode(SaveMode.Overwrite).parquet(outputFile)
        case "wild-fire" =>
          val from: String = args(2)
          val to: String = args(3)
          val outputFile: String = args(4)
          sparkSession.read.parquet(inputFile)
            .createOrReplaceTempView("wildfire")
          println("Name\tfire_intensity")
          sparkSession.sql(
            s"""
              SELECT wildfire.County, SUM(frp) AS frpCount
              FROM wildfire
              WHERE TO_DATE(wildfire.acq_date, 'yyyy-MM-dd') BETWEEN TO_DATE('$from', 'MM/dd/yyyy') AND TO_DATE('$to', 'MM/dd/yyyy')
              GROUP BY County
            """).createOrReplaceTempView("frp_count")
          sparkContext.shapefile("tl_2018_us_county.zip")
            .toDataFrame(sparkSession)
            .createOrReplaceTempView("counties")
          sparkSession.sql(
            s"""
                  SELECT NAME, g, frpCount, GEOID
                  FROM frp_count, counties
                  WHERE GEOID = County
                """).toSpatialRDD
            .coalesce(1)
            .saveAsShapefile(outputFile)
        case "temporal" =>
          val county : String = args(2)
          val wildfireDB = sparkSession.read.parquet(inputFile)
          wildfireDB.createOrReplaceTempView("wildfire")

          sparkContext.shapefile("tl_2018_us_county.zip")
            .toDataFrame(sparkSession)
            .createOrReplaceTempView("counties")
          sparkSession.sql(
            s"""
             SELECT NAME, counties.GEOID
             FROM counties
             WHERE STATEFP="06" AND NAME="$county"
          """)//.foreach(row => println(s"${row.get(0)}\t${row.get(1)}"))
            .createOrReplaceTempView("countyGEOID")
          val output = sparkSession.sql(
            s"""
            SELECT SUBSTRING(wildfire.acq_date, 0,7) AS year_month, SUM(frp) AS fire_intensity
            FROM wildfire, countyGEOID
            WHERE wildfire.County = countyGEOID.GEOID
            GROUP BY wildfire.acq_date
            ORDER BY wildfire.acq_date
          """).toDF()

          val outputFileName: String = "wildfires" + county
          output.write.mode(SaveMode.Overwrite).csv(outputFileName)
        case _ => validOperation = false
      }
      val t2 = System.nanoTime()
      if (validOperation)
        println(s"Operation '$operation' on file '$inputFile' took ${(t2 - t1) * 1E-9} seconds")
      else
        Console.err.println(s"Invalid operation '$operation'")
    } finally {
      sparkSession.stop()
    }
  }
}
