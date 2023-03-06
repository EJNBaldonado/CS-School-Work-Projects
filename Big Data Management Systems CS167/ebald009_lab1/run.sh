#!/usr/bin/env sh
mvn clean package
hadoop jar target/ebald009_lab1-1.0-SNAPSHOT.jar input.txt output.txt