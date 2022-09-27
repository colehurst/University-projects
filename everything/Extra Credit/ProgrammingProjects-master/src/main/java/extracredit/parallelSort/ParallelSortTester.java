package extracredit.parallelSort;

import java.util.Arrays;
import java.util.Comparator;

/**
 *
 * @author vangelis
 */
public class ParallelSortTester {
    
    private final static int CPU_CORES = Runtime.getRuntime().availableProcessors();
    //private final static int CORES = 1;


    public static void main(String[] args) throws Throwable {
        runSortTester(CPU_CORES);
    }
    
    public static void runSortTester(int threadCount) {
        int LENGTH = 32768000;   // length of array to sort
        Integer[] a = SortTester.createRandomArray(LENGTH);
        
        Comparator<Integer> comp = new Comparator<Integer>() {
            public int compare(Integer d1, Integer d2) {
                return d1.compareTo(d2);
            }
        };

        // run the algorithm and time how long it takes to sort the elements
        long startTime = System.currentTimeMillis();
        
        // UNCOMMENT THIS AFTER IMPLEMENTING ParallelMergeSorter
        //ParallelMergeSorter.sort(a, comp, threadCount);
        long endTime = System.currentTimeMillis();

        if (!SortTester.isSorted(a, comp)) {
            throw new RuntimeException("Not sorted!");
        }

        System.out.printf("%10d elements  =>  %6d ms \n", LENGTH, endTime - startTime);
    }
}
