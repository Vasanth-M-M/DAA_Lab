#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insertSorted(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
int main() {
    int n, i, j;
    int a[100];
    printf("Name: M M VASANTH\n");
    printf("Roll Number: CH.SC.U4CSE24227\n\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements (0–99):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    struct Node* buckets[10] = { NULL };
    for (i = 0; i < n; i++) {
        int index = a[i] / 10; 
        buckets[index] = insertSorted(buckets[index], a[i]);
    }
    printf("\nSorted array:\n");
    for (i = 0; i < 10; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    return 0;
}
