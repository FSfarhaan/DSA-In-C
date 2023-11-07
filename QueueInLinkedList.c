#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

// Initializing the front and rear to be NULL;
struct Node * f = NULL;
struct Node * r = NULL;

void enQueue() {
    int val;
    printf("Enter the value of the node: ");
    scanf("%d", &val);

    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = NULL;

    // Case for inserting first node;
    if(f == NULL) {
        f = r = newNode;
    }

    // Case for inserting other than first node;
    else {
        r -> next = newNode;
        r = newNode;
    }
    printf("The value %d has been inserted.\n\n", val);
}

void deQueue() {
    int val;
    struct Node * ptr;
    ptr = f;
    if(f == NULL) printf("Queue is empty.\n");
    else {
        f = f -> next;
        val = ptr -> data;
        free(ptr);
        printf("%d value has been removed.\n", val);
    }
}

void displayLinkedList() {
    if(f == NULL) printf("\nThe queue is empty.\n");
    else {
        struct Node * ptr;
        ptr = f;
        while(ptr != NULL) {
            printf("%d, ", ptr -> data);
            ptr = ptr -> next;
        }
        printf("\n\n");
    }
}

int main() {
    while(1) {
        int choice;
        printf("Enter your choice: \n1: Enqueue \n2: Dequeue \n3: Display Linked List \n4: Exit \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: enQueue();
            break;
        case 2: deQueue();
            break;
        case 3: displayLinkedList();
            break;
        case 4: exit(0);
            break;
        default: printf("Enter a valid choice.\n");
            break;
        }
    }
    return 0;
}