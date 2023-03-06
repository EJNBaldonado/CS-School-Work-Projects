# Lab 4

## Student information

* Full name: Eugene Baldonado
* E-mail: ebald009@ucr.edu
* UCR NetID: ebald009
* Student ID: 862070316

## Answers

* (Q1) What do you think the line `job.setJarByClass(Filter.class);` does?  
I believe the job.setJarByClass(Filter.class) takes the jar type the nodes for the application are sent to for mapping and reducing; this instance based off of the Filter program.

* (Q2) What is the effect of the line `job.setNumReduceTasks(0);`?  
There are no reduce tasks set, so it is setting the number of reduce tasks to 0. This will in turn directly connect the map task to the distributed file system, skipping any shuffling/sorting/reducing since there are no reduce tasks.

* (Q3) Where does the `main` function run? (Driver node, Master node, or an executor node).  
I believe the main function runs on the Driver node. 

* (Q4) How many lines do you see in the output?  
27972 lines

* (Q5) How many files are produced in the output?  
4 files: ._SUCCESS.crc .part-m-00000.crc _SUCCESS and part-m-00000

* (Q6) Explain this number based on the input file size and default block size.  
The task is run through the mapper in the Filter program (there is only one so m-0000), and produces an output file. The file part-m-0000 contains all the 27972 records which have a response code of 200.
* (Q7) How many files are produced in the output?  
  2 files: _SUCCESS part-m-00000
* (Q8) Explain this number based on the input file size and default block size.  
The task is run through the mapper in the Filter program (there is only one so m-0000), and produces an output file. The file part-m-0000 contains all the 27972 records which have a response code of 200.
* (Q9) How many files are produced in the output directory and how many lines are there in each file?  
  3 files: _SUCCESS (0) part-r-00000 (36) part-r-00001 (0)
* (Q10) Explain these numbers based on the number of reducers and number of response codes in the input file.  
There are 2 reducers, and since there are no keys with odd response codes, only the reducer assigned to even response codes has lines in its file.
* (Q11) How many files are produced in the output directory and how many lines are there in each file?  
  3 files: _SUCCESS (0) part-r-00000 (43) part-r-00001 (12)
* (Q12) Explain these numbers based on the number of reducers and number of response codes in the input file.  
There are 2 reducers both of them are being used over the entire file, one being assigned to even responsecode keys, and the other to odd response code keys. Here we see that there are line outputs in both the part-r files.
* (Q13) How many files are produced in the output directory and how many lines are there in each file?  
  3 files: _SUCCESS (0) part-r-00000 (13) part-r-00001 (0)
* (Q14) Explain these numbers based on the number of reducers and number of response codes in the input file.  
After isolating the response codes with filter, the amount of lines in the files is reduced from prior running with the filter class, since they are filtered by 200, there are only even response codes and no odd ones; therefore only one reducer is used.
