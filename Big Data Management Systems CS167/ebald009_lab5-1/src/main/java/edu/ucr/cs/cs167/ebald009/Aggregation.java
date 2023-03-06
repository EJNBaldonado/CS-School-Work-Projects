package edu.ucr.cs.cs167.ebald009;

import org.apache.spark.SparkConf;
import org.apache.spark.api.java.JavaPairRDD;
import org.apache.spark.api.java.JavaRDD;
import org.apache.spark.api.java.JavaSparkContext;
import org.apache.spark.api.java.function.PairFunction;
import scala.Tuple2;

import java.util.Map;

//import java.io.File;
//import java.io.IOException;
//import java.io.PrintStream;

public class Aggregation {
    public static void main(String[] args) throws IOException {  
        final String inputPath = args[0];
//	final String outputPath = args[1]; //added
//	File file = new File(outputPath);
//	PrintStream stream = new PrintStream(file);
//	System.setOut(stream);  //This set system.out to a file (aggregation_output)
        SparkConf conf = new SparkConf();
        if (!conf.contains("spark.master"))
            conf.setMaster("local[*]");
        System.out.printf("Using Spark master '%s'\n", conf.get("spark.master"));
        conf.setAppName("CS167-Lab5");
        try (JavaSparkContext spark = new JavaSparkContext(conf)) {
            JavaRDD<String> logFile = spark.textFile(inputPath).cache();
            JavaPairRDD<String, Integer> codes = logFile.mapToPair(new PairFunction<String, String, Integer>() {// To do 1: transform via `mapToPair`, return `Tuple2`
		@Override
		public Tuple2<String, Integer> call(String s) {
			String code = s.split("\t")[5];
			return new Tuple2<String,Integer>(code, 1);
		}
	    });

            Map<String, Long> counts = codes.countByKey(); // To do 2: `countByKey`
            for (Map.Entry<String, Long> entry : counts.entrySet()) {
                System.out.printf("Code '%s' : number of entries %d\n", entry.getKey(), entry.getValue());
		}
            }
    }
}
