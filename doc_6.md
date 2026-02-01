# Q6 - min and max heap

two heaps built by inserting one element at a time and bubbling up. stored in arrays.

## structure

just int arrays, minHeap[] and maxHeap[], with size counters. the heap property means for index i, parent is at (i-1)/2. children are at 2i+1 and 2i+2. no separate struct needed.

## functions

- swapInt - swaps two ints
- insertMin - puts new value at the end of the array then bubbles it up. keeps swapping with parent as long as parent is bigger (min heap property)
- insertMax - same but bubbles up as long as parent is smaller (max heap property)
- printHeap - just prints the array, the array representation is the heap

## main

hardcoded 7 numbers, inserted each into both heaps, printed both results

## output

```
Input array: 35 10 50 15 30 20 45 

Min Heap: 10 15 20 35 30 50 45 
Max Heap: 50 35 45 10 30 20 15 
```
