#include <stdio.h>
#include <stdlib.h>

enum Color {RED, BLACK};

struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};

struct Node* root = NULL;

void leftRotate(struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node *x) {
    struct Node *y = x->left;
    x->left = y->right;
    if (y->right != NULL) y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void fixViolation(struct Node *pt) {
    struct Node *parent_pt = NULL;
    struct Node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            struct Node *uncle_pt = grand_parent_pt->right;
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    leftRotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rightRotate(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        } else {
            struct Node *uncle_pt = grand_parent_pt->left;
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rightRotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                leftRotate(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

void insert(const int data) {
    struct Node *pt = (struct Node*)malloc(sizeof(struct Node));
    pt->data = data;
    pt->color = RED;
    pt->left = pt->right = pt->parent = NULL;

    if (root == NULL) {
        pt->color = BLACK;
        root = pt;
        return;
    }

    struct Node *curr = root, *parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (pt->data < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    pt->parent = parent;
    if (pt->data < parent->data) parent->left = pt;
    else parent->right = pt;

    fixViolation(pt);
}

void inorder(struct Node *n) {
    if (n == NULL) return;
    inorder(n->left);
    printf("%d(%s) ", n->data, n->color == RED ? "R" : "B");
    inorder(n->right);
}

int main() {
    int n, val;
    printf("Name: M M VASANTH\n");
    printf("Roll No: CH.SC.U4CSE24227\n\n");
    printf("Enter number of elements to insert in RB Tree: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }
    printf("Inorder Traversal (Sorted with Colors): \n");
    inorder(root);
    printf("\n");
    return 0;
}
