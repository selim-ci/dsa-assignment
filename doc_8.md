# Q8 - sorting with stats

generates random numbers, lets user pick a sort algorithm, sorts them and shows comparison/swap counts.

## data structure

just an int array arr[]. two global long long counters, comparisons and swaps, that get incremented inside the sorting functions. reset to 0 before each sort.

also a temp[] array used by merge sort for the merging step.

## functions

- swap - swaps two elements and increments swaps counter
- bubbleSort - nested loops, compares adjacent pairs, swaps if out of order
- selectionSort - for each position finds the minimum of the remaining unsorted part and swaps it in
- insertionSort - takes each element and shifts it left until its in the right place. counts each shift as a swap
- merge - merges two sorted halves using temp array, counts comparisons
- mergeSort - recursive split and merge. note: merge sort doesnt really have swaps so that counter isnt shown for it
- printArr - prints the array

## main

asks for N, generates N random numbers between 1 and 1000 using rand(). prints unsorted array. shows menu for algorithm choice. sorts. prints sorted array. prints comparisons and swaps (swaps not shown for merge sort).

## output

```
Enter N: 5

Before sorting:
742 158 934 301 617 

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Choice: 1

Bubble Sort applied.

After sorting:
158 301 617 742 934 

Comparisons: 10
Swaps: 6
```
