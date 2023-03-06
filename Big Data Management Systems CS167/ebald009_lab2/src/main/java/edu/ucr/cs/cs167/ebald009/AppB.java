package edu.ucr.cs.cs167.ebald009;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.*;


public class AppB
{
    public static void main( String[] args ) throws Exception{
        if(args.length != 1) {
            System.err.println("Incorrect number of arguments! Expected two arguments.");
            System.exit(-1);
        }

        Configuration conf = new Configuration();
        Path input = new Path(args[0]);
        FileSystem fs = input.getFileSystem(conf);

        // `input` is a Path variable in step 3
        if(!fs.exists(input)) {
            System.err.printf("Input file '%s' does not exist!\n", input);
            System.exit(-1);
        }

        FSDataInputStream inputRead = fs.open(input);
        long bytesLength = fs.getFileStatus(input).getLen();
        long minPos = bytesLength - 8193;
        byte[] b = new byte[8192];
        long bytesRead = 0;

        long startTime = System.nanoTime();

        for(int i = 0; i < 10000; ++i){
            // Get a position in input file that can read 8192 bytes without going past the end of the file
            long randPos = (long)(Math.random() * minPos);
            bytesRead += inputRead.read(randPos,b,0,8192);
        }

        long endTime = System.nanoTime();

        System.out.printf("Read %d bytes from '%s' from 10000 random positions in %f seconds\n",
                bytesRead, input, (endTime - startTime) * 1E-9);
    }
}
