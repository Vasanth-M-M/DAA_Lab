#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
       return root;
    
    if (root->key < key)
       return search(root->right, key);
 
    return search(root->left, key);
}

int main() {
    struct Node* root = NULL;
    int n, i, val, key;
    printf("Name: M M VASANTH\n");
    printf("Roll No: CH.SC.U4CSE24227\n\n");
    
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder Traversal (Sorted): ");
    inorder(root);
    printf("\n");

    printf("Enter element to search: ");
    scanf("%d", &key);
    if(search(root, key) != NULL)
        printf("Element Found\n");
    else
        printf("Element Not Found\n");

    return 0;
}
