#include <stdio.h>
void heapify(int a[], int n, int i) {
    int smallest = i; 
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && a[left] < a[smallest])
        smallest = left;
    if(right < n && a[right] < a[smallest])
        smallest = right;
    if(smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        heapify(a, n, smallest);
    }
}
int main() {
    int a[100], n, i;
    printf("Name: M M VASANTH\n");
    printf("Roll Number: CH.SC.U4CSE24227\n\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    } 
    for(i = n/2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for(i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
    printf("\nSorted array (descending order):\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
