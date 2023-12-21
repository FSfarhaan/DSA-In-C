
// Implementing Linked binary tree;

#include <stdio.h>
#include <stdlib.h>

// Initializing the structure of a binary tree;
struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data) {
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void preOrder(struct Node * root) {
    if(root != NULL) {
        printf("%d ", root -> data);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

void postOrder(struct Node * root) {
    if(root != NULL) {
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d ", root -> data);
    }
}

void inOrder(struct Node * root) {
    if(root != NULL) {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

 
int main() {

/*       4
        /  \
       1    6
      /  \
     5    2        */

    struct Node * p1 = createNode(4);
    struct Node * p2 = createNode(1);
    struct Node * p3 = createNode(6);
    struct Node * p4 = createNode(5);
    struct Node * p5 = createNode(2);

    p1 -> left = p2;
    p1 -> right = p3;
    p2 -> left = p4;
    p2 -> right = p5;

    printf("Nodes created successfully\n\n");

    preOrder(p1);
    printf("\n");
    postOrder(p1);
    printf("\n");
    inOrder(p1);
    return 0;
}