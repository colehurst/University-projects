# Extra Credit 4pt is due May 10th at 11:59 p.m.

Extra credit can be done either individually or with a partner. If you are working with a partner, BOTH need to submit a version to respective class repositories - specify both names in the submitted document.

## Submission 

* edit README.md for design pattern description (Task 1)
* edit files in parallelsort for parallel processing (Task 2) 
* Submit to your git repository -> all files should be under extracredit folder  
* If you are working with a partner, BOTH need to submit a version to respective class repositories - specify both names in the submitted documents.

## Problem Description

MergeSort is a sorting algorithm that can be easily parallelized due its divide-and-conquer nature. On CPUs with multiple cores, multiple threads can speed up the sorting time, by splitting the work. Provided source code in extracredit/sortanimation sorts a set of numbers using the top-down MergeSort  algorithm. In the given implementation, the program uses a single thread to sort the whole input.  MergeSort is a divide-and-conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.

## Task 1: 2 pt 

Describe design patterns found in the provided **sortanimation** package by editing this Section. For each filename, fill in the tables for design patterns as follow:

* Submission: edit the table below

| Filename | Line Number | Design Pattern | Implementation description (short):   |
| ---------------------- | ----------- |---------------------- | ---------------- |
| <AnimationTester.java> | <Line_11>   | <Iterator Pattern> | This is ran everytime the program is run and starts the Whole GUI |
| <AnimationTester.java> | <Line_17>   | <Decorator Pattern> | This calls the ArrayComponent class to create a clean GUI |
| <AnimationTester.java> | <Line_30>   | <Composite Pattern> | Creates a a set amount of unique variables that will be edited in a merge sort uniformly |
| <AnimationTester.java> | <Line_38>   | <Strategy Pattern> | Calls Sorter class which calls the merge sorter class within |
| <AnimationTester.java> | <Line_54>   | <Strategy Pattern> | Allows Threads to do all the work and this is the function that closes |
| <AnimationTester.java> | <Line_55>   | <Strategy Pattern> | Organizes everything thread to comb out the output for the GUI |
| <ArrayComponent.java>  | <Line_12>   | <Layout Manager> | initializes the GUI and creates a organized layout |
| <MergeSorter.java>     | <Line_8>   | <Iterator Pattern> | calls merge sorter recursively until every value in the mere sorter is sorted  |
| <Sorter.java>          | <Line_10>   | <Iterator Pattern> | Calls different parts of merge sort using individual threading |
 
## Task 2:  2 pt 

Parallelize `MergeSorter` in **parallelSort** package.  
* Use the provided code in `parallelSort` as a starting point for this task.  
* Create a new class `ParallelMergeSorter`. Copy and modify the code from `MergeSorter` class. 
* `ParallelMergeSorter` class should make use of multiple threads to perform the sorting task. 
* To make sure that your parallelized `MergeSorter` works correctly, use the method `isSorted`, of the given class SortTester which takes an array as an input argument and returns true or false, depending on if the input array is sorted or not.
* The provided `ParallelSortTester` can be used to test your `ParallelMergeSorter`.
* Check the runtimes between the single-threaded `MergeSorter` and the multi-threaded `ParallelMergeSorter`. If implemented correctly, `ParallelMergeSorter` should run faster. 

  

### The following is a pseudocode of the mergeSort method in MergeSorter class: 

```
mergeSort(arr[], l,  r)
if r > l
    Find the middle point to divide the array into two halves:  
        middle m = (l+r)/2
    Call mergeSort for first half:   
        Call mergeSort(arr, l, m)
    Call mergeSort for second half:
        Call mergeSort(arr, m+1, r)
    Merge the two halves sorted in step 2 and 3:
        Call merge(arr, l, m, r)	
```

 
The pseudocode above can be modified to allow mergeSort(arr, l, m) and mergeSort(arr, m+1, r) to run in parallel -> create new parallelMergeSort method in the new ParallelMergeSort class, e.g. 

```
parallelMergeSort(arr[], l, r, availableThreads)
if r > l
    if (availableThreads <= 1)
        mergeSort(arr[], l,  r) // Call original non-parallel mergeSort
    else
        Find the middle point to divide the array into two halves:  
            middle m = (l+r)/2
            
        Call parallelMergeSort for first half in a new thread:
            Call parallelMergeSort(arr, l, m, availableThreads/2) 
            in a new thread
            
        Call parallelMergeSort for second half in a new thread:
            Call parallelMergeSort(arr, m+1, r, availableThreads/2) 
            in a new thread
            
        Wait for threads to finish
            
        Merge the two halves sorted in previous steps:
            Call merge(arr, l, m, r)

```

Note that the pseudocode above uses the variable `availableThreads` to decide whether to allocate a new thread or not based on the number of threads that has been made available to the program. That means that every time a new thread is created, the variable `availableThreads` should be updated to reflect the number of threads that are still available.

See https://en.wikipedia.org/wiki/Merge_sort for more details about MergeSort.







