package edu.ucr.cs.cs167.ebald009;

import java.util.function.Function;

public class App 
{
    /*
    public static void printEvenNumbers(int from, int to) {
        System.out.println( "Printing numbers in the range [" + from + ',' + to + "]");
        int i = from;
        while(i <= to){
            if(i%2 == 0){
                System.out.println(i);
                i += 2;
            }
            else{
                i++;
            }
        }
    }

    public static void printOddNumbers(int from, int to) {
        System.out.println( "Printing numbers in the range [" + from + ',' + to + "]");
        int i = from;
        while(i <= to){
            if(i%2 == 1){
                System.out.println(i);
                i += 2;
            }
            else{
                i++;
            }
        }
    }

    static class IsEven implements Function<Integer, Boolean> {
        @Override
        public Boolean apply(Integer x) {
            return x % 2 == 0;
        }
    }

    static class IsOdd implements Function<Integer, Boolean> {
        @Override
        public Boolean apply(Integer x) {
            return x % 2 == 1;
        }
    }
     */

    public static void printNumbers(int from, int to, Function<Integer, Boolean> filter){
        System.out.println("Printing numbers in the range [" + from + ", " + to + "]");
        for (int i = from; i <= to; i++){
            if(filter.apply(i)){
                System.out.println(i);
            }
        }
    }

    public static Function<Integer, Boolean> combineWithAnd(Function<Integer, Boolean> ... filters) {
        Function<Integer, Boolean> filter = (x) -> {
            boolean check = true;
            for(int i = 0; i < filters.length; ++i){
                if(!filters[i].apply(x)){
                    return false;
                }
            }
            return check;
        };
        return filter;
    }

    public static Function<Integer, Boolean> combineWithOr(Function<Integer, Boolean> ... filters) {
        Function<Integer, Boolean> filter = (x) -> {
            boolean check = false;
            for(int i = 0; i < filters.length; ++i){
                if(filters[i].apply(x)){
                     return true;
                }
            }
            return check;
        };
        return filter;
    }

    public static void main( String[] args )
    {
        if(args.length != 3) {
            System.err.println("Error: At least three parameters expected, from, to, and odd.");
            System.exit(-1);
        }
        int from = Integer.parseInt(args[0]);
        int to = Integer.parseInt(args[1]);

    if (args[2].contains("v")){
            String [] strBases = args[2].split("v");

            int [] bases = new int[strBases.length];

            for(int i = 0; i < strBases.length; ++i){
                bases[i] = Integer.parseInt(strBases[i]);
            }

            Function<Integer, Boolean>[] filters = new Function[bases.length];

            for(int x = 0; x < bases.length; x++) {
                int base = bases[x];
                Function<Integer, Boolean> divisibleByBase = z -> {
                    if (z % base == 0) {
                        return true;
                    } else {
                        return false;
                    }
                };
                filters[x] = divisibleByBase;
            }
            Function<Integer, Boolean> filter = combineWithOr(filters);
            printNumbers(from, to, filter);
    }
    else if (args[2].contains("^")){
        String [] strBases = args[2].split("\\^");

        int [] bases = new int[strBases.length];

        for(int i = 0; i < strBases.length; ++i){
            bases[i] = Integer.parseInt(strBases[i]);
        }

        Function<Integer, Boolean>[] filters = new Function[bases.length];

        for(int x = 0; x < bases.length; x++) {
            int base = bases[x];
            Function<Integer, Boolean> divisibleByBase = z -> {
                if (z % base == 0) {
                    return true;
                } else {
                    return false;
                }
            };
            filters[x] = divisibleByBase;
        }
        Function<Integer, Boolean> filter = combineWithAnd(filters);
        printNumbers(from, to, filter);
    }
    else{
        int odd = Integer.parseInt(args[2]);
        if(odd < 2) {
            Function<Integer, Boolean> filter = (x) -> {
                if (x % 2 == odd % 2) {
                    return true;
                } else {
                    return false;
                }
            };
            printNumbers(from, to, filter);
        }
        else{
            Function<Integer, Boolean> filter = (x) -> {
                if (x % odd == 0) {
                    return true;
                } else {
                    return false;
                }
            };
            printNumbers(from, to, filter);
        }
    }

        /*
        Function<Integer, Boolean> filter = (x) -> {
            if(x%2 == odd%2){
                return true;
            }
            else {
                return false;
            }
        };
        printNumbers(from, to, filter);


        Function<Integer, Boolean> divisibleByFive = new Function<Integer, Boolean>() {
            @Override
            public Boolean apply(Integer x) {
                return x % 5 == 0;
            }
        };
        printNumbers(from, to, divisibleByFive);

        Function<Integer, Boolean> divisibleByTen = x -> x % 10 == 0;
        printNumbers(from, to, divisibleByTen);
         */

    }
}
