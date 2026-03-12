#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int quickSelect(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1)
            return quickSelect(arr, l, index - 1, k);
            
        return quickSelect(arr, index + 1, r, k - index + l - 1);
    }
    return -1;
}

int main() {
    int arr[] = {10, 4, 5, 8, 6, 11, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 
    
    printf("Name: M M VASANTH\n");
    printf("Roll No: CH.SC.U4CSE24227\n\n");
    printf("Array: 10 4 5 8 6 11 26\n");
    printf("The %d-th smallest element is %d\n", k, quickSelect(arr, 0, n - 1, k));
    return 0;
}
