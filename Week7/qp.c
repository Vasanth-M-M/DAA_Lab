#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

// Standard partition using the LAST element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 1. Pivot = Last Element
void quickSortLast(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortLast(arr, low, pi - 1);
        quickSortLast(arr, pi + 1, high);
    }
}

// 2. Pivot = First Element
void quickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        swap(&arr[low], &arr[high]); // Move first to last, then partition
        int pi = partition(arr, low, high);
        quickSortFirst(arr, low, pi - 1);
        quickSortFirst(arr, pi + 1, high);
    }
}

// 3. Pivot = Middle Element
void quickSortMid(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        swap(&arr[mid], &arr[high]); // Move mid to last, then partition
        int pi = partition(arr, low, high);
        quickSortMid(arr, low, pi - 1);
        quickSortMid(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int arr3[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    printf("Name: M M VASANTH\n");
    printf("Roll No: CH.SC.U4CSE24227\n\n");

    quickSortLast(arr1, 0, n - 1);
    printf("Sorted using LAST element as pivot: ");
    printArray(arr1, n);

    quickSortFirst(arr2, 0, n - 1);
    printf("Sorted using FIRST element as pivot: ");
    printArray(arr2, n);

    quickSortMid(arr3, 0, n - 1);
    printf("Sorted using MIDDLE element as pivot: ");
    printArray(arr3, n);

    return 0;
}
