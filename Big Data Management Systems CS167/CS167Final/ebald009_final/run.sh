#!/usr/bin/env sh
mvn clean package
spark-submit --class edu.ucr.cs.cs167.ebald009.BeastScala --master "local[*]" target/ebald009_final-1.0-SNAPSHOT.jar data-prep wildfiredb_10k.csv convert_output
spark-submit --class edu.ucr.cs.cs167.ebald009.BeastScala --master "local[*]" target/ebald009_final-1.0-SNAPSHOT.jar wild-fire convert_output 01/01/2016 12/31/2017 wildfireIntensityCounty
spark-submit --class edu.ucr.cs.cs167.ebald009.BeastScala --master "local[*]" target/ebald009_final-1.0-SNAPSHOT.jar temporal convert_output Riverside