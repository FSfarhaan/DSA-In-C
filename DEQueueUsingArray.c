// Implementing a Double Ended Queue using Array;

#include <stdio.h>

#define MAX 10
int arr[MAX];
int front = -1;
int rear = -1;

void enQueueFront(int val) {
    if(front <= 0) printf("Cannot enqueue from front\n");
    else {
        arr[--front] = val;
    }
}

void enQueueRear(int val) {
    if(rear == MAX - 1) printf("The Queue is full\n");
    else {
        if(front == -1) front++;
        arr[++rear] = val;
    }
}

void deQueueFront() {
    if(front == -1) printf("The Queue is emptyF\n");
    else {
        if(rear == front) front = rear = -1;
        else front++;
    }
}

void deQueueRear() {
    if(rear == -1) printf("The Queue is emptyR\n");
    else {
        if(rear == front) front = rear = -1;
        else {
            rear--;
        }
    }
}

void display() {
    if(rear == -1) printf("The Queue is emptyD\n");
    else {
        printf("The elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
}

int main() {
    // deQueueFront();
    // deQueueRear();
    // enQueueFront(45);
    // display();
    printf("Adding elements normally\n");
    enQueueRear(10);
    enQueueRear(20);
    enQueueRear(30);
    enQueueRear(40);
    enQueueRear(50);
    enQueueRear(60);
    enQueueRear(70);
    enQueueRear(80);
    enQueueRear(90);
    enQueueRear(100);
    // enQueueRear(110);
    display();

    printf("\nAfter dequeueing from front\n");
    deQueueFront();
    deQueueFront();
    deQueueFront();
    display();

    printf("\nAfter dequeueing from rear\n");
    deQueueRear();
    deQueueRear();
    deQueueRear();
    display();

    printf("\nAfter enqueueing from front\n");
    enQueueFront(30);
    enQueueFront(20);
    display();

    printf("\nRemoving all the elements from rear\n");
    deQueueRear();
    deQueueRear();
    deQueueRear();
    deQueueRear();
    deQueueRear();
    deQueueRear();
    deQueueRear();
    enQueueFront(45);
    display();

    printf("\nAdding again\n");
    enQueueRear(120);
    enQueueRear(130);
    enQueueRear(140);
    enQueueRear(150);
    enQueueRear(160);
    display();
    
    // enQueueRear();
    return 0;
}