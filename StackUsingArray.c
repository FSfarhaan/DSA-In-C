// Implementing a stack using an array.

#include <stdio.h>
#include <stdlib.h>

// Initializing a Stack.
int stack[10];
int top = -1;

void push() {
    if(top == 9) printf("The stack is full.\n");
    else{
        int val;
        printf("Enter the value: ");
        scanf("%d", &val);

        stack[++top] = val;
        printf("%d has been inserted successfully.", val);
    }
}

void pop() {
    if(top == -1) printf("The stack is empty.\n");
    else {
        int val = stack[top--];
        printf("%d has been removed successfully", val);
    }
}

void display() {
    if(top == -1) printf("The stack is empty.\n");
    else {
        printf("The elements are: ");
        for(int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void peek() {
    if(top == -1) printf("The stack is empty.\n");
    else {
        int position;
        printf("Enter the position: ");
        scanf("%d", &position);

        if(top - position + 1 >= 0) printf("The value at position %d is %d.", position, stack[top - position + 1]);
        else printf("Enter a valid position.\n");
    }
}

void stackTop() {
    if(top == -1) printf("The stack is empty.\n");
    else printf("The value at top is %d", stack[top]);
}

void stackBottom() {
    if(top == -1) printf("The stack is empty.\n");
    else printf("The value at bottom is %d", stack[0]);
}

void menu() {
    while(1) {
        int choice;
        printf("\n\n1. Push \n2. Pop \n3. Display \n4. Peek \n5. Element at top \n6. Element at bottom \n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3: display();
            break;
        case 4: peek();
            break;
        case 5: stackTop();
            break;
        case 6: stackBottom();
            break;
        case 7: exit(0);
        default: printf("Enter a valid choice.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}