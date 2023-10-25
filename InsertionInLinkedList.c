/* 
This is a program to demonstrate various ways to insert a node in a linked list;
1. Insertion at beginning;
2. Insertion at end;
3. Insertion after a node;
4. Insertion before a node;
5. Insertion at an index;
*/

#include <stdio.h>
#include <stdlib.h>

// Defining the structure Node;
struct Node {
    int data;
    struct Node * next;
};

// Function to traverse in a Linked List;
void LinkedListTraversal(struct Node * head) {
    struct Node * ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

// Function to insert a node at the beginning;
struct Node * InsertAtBeg(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;

    return ptr;
}

// Function to insert a node at the end;
struct Node * InsertAtEnd(struct Node * head, int data) {
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    
    struct Node * ptr;
    ptr = head;

    while(ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    ptr -> next = newNode;
    return head;
}

// Function to insert a node after a node;
struct Node * InsertAfterNode(struct Node * head, int data, int afterNode) {
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = data;

    struct Node * ptr;
    ptr = head;

    while(ptr -> data != afterNode) {
        ptr = ptr -> next;
    }
    newNode -> next = ptr -> next;
    ptr -> next = newNode;    

    return head;
}

// Function to insert a node before a node;
struct Node * InsertBeforeNode(struct Node * head, int data, int beforeNode) {
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = data;

    struct Node * ptr;
    ptr = head;

    while(ptr -> next -> data != beforeNode) {
        ptr = ptr -> next;
    }
    newNode -> next = ptr -> next;
    ptr -> next = newNode;    

    return head;
}

// Function to insert a node at an Index;
struct Node * InsertAtIndex(struct Node * head, int data, int index) {
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = data;

    struct Node * ptr;
    ptr = head;
    
    for(int i = 0; i < index - 1; i++) {
        ptr = ptr -> next;
    }

    newNode -> next = ptr -> next;
    ptr -> next = newNode;    

    return head;
}
 
int main() {

    // Initiating the nodes;
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    // Defining data in the nodes;
    head -> data = 7;
    head -> next = second;
    second -> data = 14;
    second -> next = third;
    third -> data = 24;
    third -> next = fourth;
    fourth -> data = 45;
    fourth -> next = NULL;

    // Traversion in the node;
    LinkedListTraversal(head);

    // Inserting at the beginning;
    printf("Linked List before Insertion: \n");
    LinkedListTraversal(head);
    printf("\nLinked list after Insertion: \n");
    head = InsertAtBeg(head, 56);
    LinkedListTraversal(head);

    // Inserting at end;
    printf("Linked List before Insertion: \n");
    LinkedListTraversal(head);
    printf("\nLinked list after Insertion: \n");
    head = InsertAtEnd(head, 6);
    LinkedListTraversal(head);

    // Inserting after a node;
    printf("Linked List before Insertion: \n");
    LinkedListTraversal(head);
    printf("\nLinked list after Insertion: \n");
    head = InsertAfterNode(head, 35, 14);
    LinkedListTraversal(head);

    // Inserting before a node;
    printf("Linked List before Insertion: \n");
    LinkedListTraversal(head);
    printf("\nLinked list after Insertion: \n");
    head = InsertBeforeNode(head, 5, 45);
    LinkedListTraversal(head);

    // Inserting a node at an index. Index begins with 0;
    printf("Linked List before Insertion: \n");
    LinkedListTraversal(head);
    printf("\nLinked list after Insertion: \n");
    head = InsertAtIndex(head, 10, 1);
    LinkedListTraversal(head);

    return 0;
}