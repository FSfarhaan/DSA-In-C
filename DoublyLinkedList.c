#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
};

void traverseForward(struct Node * head) {
    struct Node * ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

void traverseBackward(struct Node * last) {
    struct Node * ptr = last;
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> prev;
    }
}

int main() {
    struct Node * head = malloc(sizeof(struct Node));
    struct Node * second = malloc(sizeof(struct Node));
    struct Node * third = malloc(sizeof(struct Node));
    struct Node * fourth = malloc(sizeof(struct Node));

    head -> data = 7;
    head -> prev = NULL;
    head -> next = second;
    second -> data = 17;
    second -> prev = head;
    second -> next = third;
    third -> data = 27;
    third -> prev = second;
    third -> next = fourth;
    fourth -> data = 37;
    fourth -> prev = third;
    fourth -> next = NULL;

    traverseForward(head);
    printf("\n\n");
    traverseBackward(fourth);
    return 0;
}