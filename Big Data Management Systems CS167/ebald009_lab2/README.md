# Lab 2

## Student information

* Full name: Eugene Baldonado
* E-mail: ebald009@ucr.edu
* UCR NetID: ebald009
* Student ID: 862070316

## Answers

* (Q1) Verify the file size and record the running time.  
Copied 2271219010 bytes from 'AREAWATER.csv/AREAWATER.csv' to 'output.txt' in 18.556916  
NOTE: After this first example I moved the file out of the folder generated from unzipping so that I would only need to write 'AREAWATER.csv', additionally this was done using the copyToLocalFile method of the fileSystem class.

* (Q2) Record the running time of the copy command.  
The copy method in powershell (Copy-Item) performed the copy on the local file system in 3.9856034 seconds.  
The output from the Measure-Command method was:  
Seconds           :  3  
Milliseconds      :  985  
Ticks             :  39856034  
TotalDays         :  4.61296689814815E-05  
TotalHours        :  0.00110711205555556  
TotalMinutes      :  0.0664267233333333  
TotalSeconds      :  3.9856034  
TotalMilliseconds :  3985.6034

* (Q3) How do the two numbers compare? (The running times of copying the file through your program and the operating system.) Explain IN YOUR OWN WORDS why you see these results.  
The running times of copying the file through the program to running the files on the operating system differed as the program must open and close the files for input and for output, and therefore takes longer than locally on the operating systems where the files are located. This difference can be seen in the time difference, where the program took 18.5 seconds and the operating system performed the copy in a little less than 4 seconds.

* (Q4) Does the program run after you change the default file system to HDFS? What is the error message, if any, that you get?  
The program doesn't run after changing the default file system to HDFS, the error message that outputs is:  
  Exception in thread "main" java.net.ConnectException: Call From LAPTOP-V4PU60T8/169.235.86.88 to localhost:9000 failed on connection exception: java.net.ConnectException: Connection refused: no further information;  
This is because to properly use the HDFS in the input and output arguments, it must be specified whether it is from a file:/// or from hdfs:///. Another possible error is "AREAWATER.csv already exists!" when trying to running the copy when it already exists.
* (Q5) Use your program to test the following cases and record the running time for each case.

| From  |  To   | Run Time (seconds) |
|:-----:|:-----:|:------------------:|
| Local | HDFS  |     25.655695      |
| HDFS  | Local |     15.741252      |  
| HDFS  | HDFS  |     13.787133      |  



* (Q6) Test your program on two files, one file stored on the local file system, and another file stored on HDFS. Compare the running times of both tasks. What do you observe?  
  Read 81920000 bytes from 'file:/C:/cs167/workspace/ebald009_lab2/AREAWATER.csv' from 10000 random positions in 5.616004 seconds  
  Read 81920000 bytes from 'hdfs://localhost:9000/user/eugen/AREAWATER.csv' from 10000 random positions in 7.466150 seconds  
  It can be seen that the program used on the local file system performed marginally faster than using the HDFS file system. 

