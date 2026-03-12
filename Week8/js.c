#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Job {
    char id;
    int dead;
    int profit;
};

int compare(const void* a, const void* b) {
    struct Job* temp1 = (struct Job*)a;
    struct Job* temp2 = (struct Job*)b;
    return (temp2->profit - temp1->profit); // Sort descending by profit
}

int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(struct Job arr[], int n) {
    qsort(arr, n, sizeof(struct Job), compare);

    int result[n]; 
    bool slot[n];  

    for (int i = 0; i < n; i++) slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i; 
                slot[j] = true; 
                break;
            }
        }
    }

    printf("Following is maximum profit sequence of jobs: \n");
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%c ", arr[result[i]].id);
            totalProfit += arr[result[i]].profit;
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    struct Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                         {'d', 1, 25}, {'e', 3, 15} };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Name: M M VASANTH\n");
    printf("Roll No: CH.SC.U4CSE24227\n\n");
    printJobScheduling(arr, n);
    return 0;
}
