mvn clean package
hadoop jar target/ebald009_lab2-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.App file:///$pwd/AREAWATER.csv hdfs:///AREAWATER.csv
hadoop jar target/ebald009_lab2-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.App hdfs:///AREAWATER.csv file:///$pwd/AREAWATER_copy.csv
hadoop jar target/ebald009_lab2-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.App hdfs:///AREAWATER.csv hdfs:///AREAWATER_copy.csv
hadoop jar target/ebald009_lab2-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.AppB file:///$pwd/AREAWATER.csv
hadoop jar target/ebald009_lab2-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.AppB hdfs:///AREAWATER.csv