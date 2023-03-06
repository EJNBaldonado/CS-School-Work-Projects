mvn clean package

yarn jar target/ebald009_lab4-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.Filter hdfs:///nasa_19950801.tsv hdfs:///filter_output 200

yarn jar target/ebald009_lab4-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.Aggregation hdfs:///filter_output hdfs:///aggregation_output
