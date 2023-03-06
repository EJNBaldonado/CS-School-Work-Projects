# Lab 5

## Student information

* Full name: Eugene Baldonado
* E-mail: ebald009@ucr.edu
* UCR NetID: ebald009
* Student ID: 862070316

## Answers

* (Q1) Do you think it will use your local cluster? Why or why not?  
Yes, the context that spark is under in out App.java is set to "local" therefore, it does not know to access the cluster that is started. This can be seen as our website (localhost:8080) is not updated with any tasks.  
* (Q2) Does the application use the cluster that you started? How did you find out?  
Yes, after changing the context to the spark cluster, we can see that the application uses the cluster that is started. This can be seen in the localhost:8080 website, as after running the command it produces a completed application (Application ID: app-20220430180052-0000) with the state FINISHED and a duration of 4s.  
* (Q3) What is the Spark master printed on the standard output on IntelliJ IDEA?  
After running this is the Spark master printed on the standard output on the terminal: Using Spark master 'local[*]'  
* (Q4) What is the Spark master printed on the standard output on the terminal?  
After running this is the Spark master printed on the standard output on the terminal: Using Spark master 'spark://127.0.0.1:7077'.   
* (Q5) For the previous command that prints the number of matching lines, list all the processed input splits.  
2022-05-04 21:23:47,547 INFO rdd.HadoopRDD: Input split: hdfs://localhost:9000/nasa_19950801.tsv:0+1169610  
2022-05-04 21:23:47,547 INFO rdd.HadoopRDD: Input split: hdfs://localhost:9000/nasa_19950801.tsv:1169610+1169610  
* (Q6) For the previous command that counts the lines and prints the output, how many splits were generated?  
2 splits  
2022-05-04 21:23:47,547 INFO rdd.HadoopRDD: Input split: hdfs://localhost:9000/nasa_19950801.tsv:0+1169610  
2022-05-04 21:23:47,547 INFO rdd.HadoopRDD: Input split: hdfs://localhost:9000/nasa_19950801.tsv:1169610+1169610  
* (Q7) Compare this number to the one you got earlier.  
They both received the same number of input splits.  
* (Q8) Explain why we get these numbers.  
The number of input splits are equal to the number of mappers; since there were 2 mappers there were two input splits, which split the file of size 2.3 mb to two parts of about 1.16 MB.  
* (Q9) What can you do to the current code to ensure that the file is read only once?  
Using the cache() function we can make sure that the RDD is cached in the memory for multiple uses. This will mean that the RDD will not have to be read through accessing the disk for each call.  
