#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int arr[MAX], temp[MAX];
int n;
long long comparisons = 0, swaps = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; swaps++; }

void bubbleSort() {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
}

void selectionSort() {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) { comparisons++; if (arr[j] < arr[minIdx]) minIdx = j; }
        if (minIdx != i) swap(&arr[i], &arr[minIdx]);
    }
}

void insertionSort() {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i-1;
        while (j >= 0 && (comparisons++, arr[j] > key)) { arr[j+1] = arr[j]; j--; swaps++; }
        arr[j+1] = key;
    }
}

void merge(int l, int m, int r) {
    int i = l, j = m+1, k = 0;
    while (i <= m && j <= r) {
        comparisons++;
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int x = 0; x < k; x++) arr[l+x] = temp[x];
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

void printArr(int *a, int sz) {
    for (int i = 0; i < sz; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int orig[MAX];
    printf("Enter N: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++) orig[i] = arr[i] = rand() % 1000 + 1;

    printf("\nBefore sorting:\n");
    printArr(arr, n);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Choice: ");
    int choice;
    scanf("%d", &choice);

    comparisons = swaps = 0;

    if (choice == 1) { bubbleSort(); printf("\nBubble Sort"); }
    else if (choice == 2) { selectionSort(); printf("\nSelection Sort"); }
    else if (choice == 3) { insertionSort(); printf("\nInsertion Sort"); }
    else if (choice == 4) { mergeSort(0, n-1); printf("\nMerge Sort"); }
    else { printf("Invalid choice\n"); return 1; }

    printf(" applied.\n\nAfter sorting:\n");
    printArr(arr, n);

    printf("\nComparisons: %lld\n", comparisons);
    if (choice != 4) printf("Swaps: %lld\n", swaps);

    return 0;
}
