mvn clean package
spark-submit --class edu.ucr.cs.cs167.ebald009.Filter --master local[2] target/ebald009_lab5-1.0-SNAPSHOT.jar nasa_19950630.22-19950728.12.tsv filter_output 302
spark-submit --class edu.ucr.cs.cs167.ebald009.Aggregation --master local[2] target/ebald009_lab5-1.0-SNAPSHOT.jar nasa_19950630.22-19950728.12.tsv aggregation_output
