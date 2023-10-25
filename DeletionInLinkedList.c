/* 
This is a program to demonstrate various ways to delete a node in a linked list;
1. Deletion at beginning;
2. Deletion at end;
3. Deletion after a node;
4. Deletion before a node;
5. Deletion of a speicified node;
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

// Function to Delete a node at the beginning;
struct Node * DeleteAtBeg(struct Node * head){
    struct Node * ptr;
    ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

// Function to Delete a node at the end;
struct Node * DeleteAtEnd(struct Node * head) {
    struct Node * ptr;
    ptr = head;

    while(ptr -> next -> next != NULL) {
        ptr = ptr -> next;
    }
    free(ptr -> next);
    ptr -> next = NULL;

    return head;
}

// Function to Delete a node after a node;
struct Node * DeleteAfterNode(struct Node * head, int afterNode) {
    struct Node * ptr;
    struct Node * preptr;
    ptr = head -> next;
    preptr = head;

    while(preptr -> data != afterNode) {
        preptr = preptr -> next;
        ptr = ptr -> next;
    }
    preptr -> next = ptr -> next;
    free(ptr);
    return head;
}

// Function to Delete a node before a node;
struct Node * DeleteBeforeNode(struct Node * head, int beforeNode) {
    struct Node * ptr;
    struct Node * preptr;
    ptr = head -> next;
    preptr = head;

    while(ptr -> next -> data != beforeNode) {
        preptr = preptr -> next;
        ptr = ptr -> next;
    }
    preptr -> next = ptr -> next;
    free(ptr);

    return head;
}

// Function to Delete a specified node
struct Node * DeleteNode(struct Node * head, int data) {
    struct Node * ptr;
    struct Node * preptr;
    ptr = head -> next;
    preptr = head;
    
    while(ptr -> data != data) {
        preptr = preptr -> next;
        ptr = ptr -> next;
    }
    preptr -> next = ptr -> next;  
    free(ptr);

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
    // LinkedListTraversal(head);

    // Deleting at the beginning;
    // printf("Linked List before Deletion: \n");
    // LinkedListTraversal(head);
    // printf("\nLinked list after Deletion: \n");
    // head = DeleteAtBeg(head);
    // LinkedListTraversal(head);

    // Deleting at end;
    // printf("Linked List before Deletion: \n");
    // LinkedListTraversal(head);
    // printf("\nLinked list after Deletion: \n");
    // head = DeleteAtEnd(head);
    // LinkedListTraversal(head);

    // Deleting after a node;
    // printf("Linked List before Deletion: \n");
    // LinkedListTraversal(head);
    // printf("\nLinked list after Deletion: \n");
    // head = DeleteAfterNode(head, 24);
    // LinkedListTraversal(head);

    // Deleting before a node;
    // printf("Linked List before Deletion: \n");
    // LinkedListTraversal(head);
    // printf("\nLinked list after Deletion: \n");
    // head = DeleteBeforeNode(head, 45);
    // LinkedListTraversal(head);

    // Deleting a node specified;
    printf("Linked List before Deletion: \n");
    LinkedListTraversal(head);
    printf("\nLinked list after Deletion: \n");
    head = DeleteNode(head, 24);
    LinkedListTraversal(head);

    return 0;
}