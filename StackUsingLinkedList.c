// Implementing a stack using Linked list.

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack * next;
};

struct Stack * top = NULL;

void push(int val) {
    struct Stack * newNode = (struct Stack *) malloc(sizeof(struct Stack));
    newNode -> data = val;
    newNode -> next = top;
    top = newNode;
}

void pop() {
    struct Stack * ptr = top;
    int val = top -> data;
    top = top -> next;
    free(ptr);
}

int peek(int position) {
    struct Stack * ptr = top;
    for(int i = 1; i < position; i++) {
        ptr = ptr -> next;
    }
    return ptr -> data;
}

void display() {
    struct Stack * ptr = top;
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    printf("Before popping\n");
    display();

    // printf("Before popping\n");
    // pop();
    // pop();
    // pop();
    // display();

    printf("\nThe element at position 3 is %d ", peek(3));
    return 0;
}