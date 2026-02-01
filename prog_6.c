#include <stdio.h>

#define MAX 100

int minHeap[MAX], maxHeap[MAX];
int minSize = 0, maxSize = 0;

void swapInt(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void insertMin(int val) {
    minHeap[minSize] = val;
    int i = minSize++;
    // bubble up
    while (i > 0 && minHeap[(i-1)/2] > minHeap[i]) {
        swapInt(&minHeap[(i-1)/2], &minHeap[i]);
        i = (i-1)/2;
    }
}

void insertMax(int val) {
    maxHeap[maxSize] = val;
    int i = maxSize++;
    while (i > 0 && maxHeap[(i-1)/2] < maxHeap[i]) {
        swapInt(&maxHeap[(i-1)/2], &maxHeap[i]);
        i = (i-1)/2;
    }
}

void printHeap(int *heap, int size, char *name) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int arr[] = {35, 10, 50, 15, 30, 20, 45};
    int n = 7;

    printf("Input array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        insertMin(arr[i]);
        insertMax(arr[i]);
    }

    printHeap(minHeap, minSize, "Min Heap");
    printHeap(maxHeap, maxSize, "Max Heap");

    return 0;
}
