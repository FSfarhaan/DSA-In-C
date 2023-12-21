
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
 
int main() {

/*       45
        /  \
       32  34
      /  \
    10   20        */

    struct Node * p1 = createNode(45);
    struct Node * p2 = createNode(32);
    struct Node * p3 = createNode(34);
    struct Node * p4 = createNode(10);
    struct Node * p5 = createNode(20);

    p1 -> left = p2;
    p1 -> right = p3;
    p2 -> left = p4;
    p2 -> right = p5;

    printf("Nodes created successfully");
    return 0;
}