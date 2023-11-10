// Implement Linear queue using array;

#include <stdio.h>
#include <stdlib.h>

int queue[10];
int front = -1;
int rear = -1;

void enqueue() {
    if(rear == 9) printf("The Queue is Full");
    else {
        int value;
        printf("Enter the value: ");
        scanf("%d", &value);
        if(rear == -1) front = 0;
        queue[++rear] = value;
        printf("Item Enqueued Successfully\n");
    }
}

void dequeue() {
    if(rear == -1 || front > rear) printf("The Queue is Empty\n");
    else if(front == rear){
        front = rear = -1;
        printf("Item Dequeued Successfully\n");
    } 
    else {
        front++;
        printf("Item Dequeued Successfully\n");
    } 
}

void display() {
    if(rear == -1 || front > rear) printf("The Queue is Empty\n");
    else {
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

void menu() {
    int choice;

    while(1) {
        printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: exit(0);
                break;
            default: printf("Enter a valid choice");
        }
    }
}

int main() {
    menu();
    return 0;
}