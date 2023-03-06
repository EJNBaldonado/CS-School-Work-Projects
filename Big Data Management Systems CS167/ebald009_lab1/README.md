# Lab 1

## Student information
* Full name: Eugene Baldonado
* E-mail: ebald009@ucr.edu
* UCR NetID: ebald009
* Student ID: 862070316

## Answers

* (Q1) What is the name of the created directory?  
ebald009_lab1
* (Q2) What do you see at the console output?  
Hello World!
* (Q3) What do you see at the output?  
  log4j:WARN No appenders could be found for logger (org.apache.hadoop.metrics2.lib.MutableMetricsFactory).  
  log4j:WARN Please initialize the log4j system properly.  
  log4j:WARN See http://logging.apache.org/log4j/1.2/faq.html#noconfig for more info.  
Process finished with exit code 1

* (Q4) What is the output that you see at the console?  
  log4j:WARN No appenders could be found for logger (org.apache.hadoop.metrics2.lib.MutableMetricsFactory).  
  log4j:WARN Please initialize the log4j system properly.  
  log4j:WARN See http://logging.apache.org/log4j/1.2/faq.html#noconfig for more info.  
Process finished with exit code 0

NOTE:
This file was created in the output.txt folder generated in the file part-r-0000.txt  
but	1  
cannot	3  
crawl	1  
do	1  
fly,	1  
forward	1  
have	1  
if	3  
keep	1  
moving	1  
run	1  
run,	1  
then	3  
to	1  
walk	1  
walk,	1  
whatever	1  
you	5  
* (Q5) Does it run? Why or why not?  
  No, this gives the error  
  Exception in thread "main" org.apache.hadoop.mapred.FileAlreadyExistsException: Output directory file:/C:/cs167/workspace/ebald009_lab1/output.txt already exists  
  This is because prior to running the file output.txt is generated.
  After deleting the output.txt file, and running the command:
  hadoop jar target/ebald009_lab1-1.0-SNAPSHOT.jar edu.ucr.cs.cs167.ebald009.App input.txt output.txt
  The program works and creates the output.txt file.
