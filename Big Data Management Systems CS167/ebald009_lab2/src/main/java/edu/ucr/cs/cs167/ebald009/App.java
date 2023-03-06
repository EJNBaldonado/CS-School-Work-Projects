package edu.ucr.cs.cs167.ebald009;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.*;


public class App 
{
    public static void main( String[] args ) throws Exception{
        //1 and 2
        if(args.length != 2) {
            System.err.println("Incorrect number of arguments! Expected two arguments.");
            System.exit(-1);
        }

        Configuration conf = new Configuration();
        //3
        Path input = new Path(args[0]);
        Path output = new Path(args[1]);
        //4
        FileSystem fs = input.getFileSystem(conf);
        FileSystem outfs = output.getFileSystem(conf);
        //5
        // `input` is a Path variable in step 3
        if(!fs.exists(input)) {
            System.err.printf("Input file '%s' does not exist!\n", input);
            System.exit(-1);
        }
        //6
        if(outfs.exists(output)) {
            // `output` is a Path variable in step 3
            System.err.printf("Output file '%s' already exists!\n", output);
            System.exit(-1);
        }
        //7
        long startTime = System.nanoTime();


//        fs.copyToLocalFile(false, input, output);
        FileUtil fu = new FileUtil();
        fu.copy(fs, input, outfs, output, false, conf);
        long bytesCopied = outfs.getFileStatus(output).getLen();

        long endTime = System.nanoTime();
        //8
// `bytesCopied` is the actual number of bytes copied.
// `input` and `output` are Path in step 3.
// `startTime` and `endTime` are the System.nanoTime() before and after the copy function.
        System.out.printf("Copied %d bytes from '%s' to '%s' in %f seconds\n",
                bytesCopied, input, output, (endTime - startTime) * 1E-9);
    }
}
