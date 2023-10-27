#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
 
void traverse(struct Node * head){
    struct Node * ptr;
    ptr = head;

    do {
        printf("%d, ", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != head);
}

struct Node * insertAtBeg(struct Node * head, int val) {
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = val;

    struct Node * ptr;
    ptr = head;

    while(ptr -> next != head) {
        ptr = ptr -> next;
    }
    ptr -> next = newNode;
    newNode -> next = head;
    head = newNode;
    return head;
}

int main() {
    struct Node * head = (struct Node *) malloc (sizeof(struct Node));
    struct Node * second = (struct Node *) malloc (sizeof(struct Node));
    struct Node * third = (struct Node *) malloc (sizeof(struct Node));
    struct Node * fourth = (struct Node *) malloc (sizeof(struct Node));

    head -> data = 7;
    head -> next = second;
    second -> data = 17;
    second -> next = third;
    third -> data = 27;
    third -> next = fourth;
    fourth -> data = 37;
    fourth -> next = head;

    printf("Before Insertion: \n");
    traverse(head);
    head = insertAtBeg(head, 67);
    head = insertAtBeg(head, 767);
    head = insertAtBeg(head, 87);
    printf("\nAfter Insertion: \n");
    traverse(head);
    return 0;
}