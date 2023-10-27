#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
struct Node * head = NULL;

int isPresent(int nodeVal) {
    struct Node * ptr;
    ptr = head;

    while(ptr -> data != nodeVal && ptr -> next != NULL){
        ptr = ptr -> next;
    }
    if(ptr -> next == NULL) {
        return 0;
    } 
    else return 1;
}

void createLinkedList(){
    int val;
    printf("Enter value to be stored: ");
    scanf("%d", &val);
    printf("A new linked list of value %d has been created.", val);

    struct Node * newNode;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = NULL;
    head = newNode;
}

void insertAtBeg() {

    if(head == NULL) printf("Create a linked list first");
    else {
        int val;
        printf("Enter value to be stored: ");
        scanf("%d", &val);
        printf("A node of value %d has been inserted. \n", val);

        struct Node *newNode;
        newNode = (struct Node *) malloc (sizeof(struct Node));
        newNode -> data = val;
        newNode -> next = head;
        head = newNode;
    }
}

void insertAtEnd() {
    if(head == NULL) printf("Create a linked list first");
    else {
        int val;
        printf("Enter value to be stored: ");
        scanf("%d", &val);
        printf("A node of value %d has been inserted. \n", val);

        struct Node *newNode;
        newNode = (struct Node *) malloc (sizeof(struct Node));
        newNode -> data = val;
        newNode -> next = NULL;

        struct Node * ptr;
        ptr = head;
        while(ptr -> next != NULL) {
            ptr = ptr -> next;
        }
        ptr -> next = newNode;  
    }
}

void insertAfter() {
    if(head == NULL) printf("Create a linked list first");
    else {
        int val, afterNode;
        printf("Enter value to be stored: ");
        scanf("%d", &val);

        printf("Enter the node to be inserted after: ");
        scanf("%d", &afterNode);

        int check = isPresent(afterNode);
        if(check == 1){
            printf("A node of value %d has been inserted. \n", val);

            struct Node *newNode;
            newNode = (struct Node *) malloc (sizeof(struct Node));
            newNode -> data = val;

            struct Node * ptr;
            ptr = head;

            while(ptr -> data != afterNode) {
                ptr = ptr -> next;
            }
            newNode -> next = ptr -> next;
            ptr -> next = newNode;
        }
        else printf("The node is not present in the linked list, try again.");
    }
}

void insertBefore() {
    if(head == NULL) printf("Create a linked list first");
    else {
        int val, beforeNode;
        printf("Enter value to be stored: ");
        scanf("%d", &val);

        printf("Enter the node to be inserted before: ");
        scanf("%d", &beforeNode);

        int check = isPresent(beforeNode);
        if(check == 1){
            printf("A node of value %d has been inserted. \n", val);

            struct Node *newNode;
            newNode = (struct Node *) malloc (sizeof(struct Node));
            newNode -> data = val;

            struct Node * ptr;
            ptr = head;

            while(ptr -> next -> data != beforeNode) {
                ptr = ptr -> next;
            }
            newNode -> next = ptr -> next;
            ptr -> next = newNode;
        }
        else printf("The node is not present in the linked list, try again.");
    }
}

void insertAtIndex() {
    if(head == NULL) printf("Create a linked list first");
    else {
        int val, index;
        printf("Enter value to be stored: ");
        scanf("%d", &val);

        printf("Enter the index: ");
        scanf("%d", &index);
        printf("A node of value %d has been inserted. \n", val);

        struct Node *newNode;
        newNode = (struct Node *) malloc (sizeof(struct Node));
        newNode -> data = val;

        struct Node * ptr;
        ptr = head;

        for(int i = 0; i < index - 1; i++) {
            ptr = ptr -> next;
        }
        newNode -> next = ptr -> next;
        ptr -> next = newNode;
    }
}

void deleteAtBeg() {
    if(head == NULL) printf("Create a linked list first");
    else {
        struct Node * ptr;
        ptr = head;
        head = ptr -> next;
        free(ptr);
        printf("A node has been deleted. \n");
    }
}

void deleteAtEnd() {
    if(head == NULL) printf("Create a linked list first");
    else {
        struct Node * ptr;
        ptr = head;

        while(ptr -> next -> next != NULL){
            ptr = ptr -> next;
        }
        free(ptr -> next);
        ptr -> next = NULL;

        printf("A node has been deleted. \n");
    }
}

void deleteAfter() {
    if(head == NULL) printf("Create a linked list first");
    else {
        int afterNode;
        printf("Enter the node to be deleted after: ");
        scanf("%d", &afterNode);

        int check = isPresent(afterNode);
        if(check == 1) {            
            struct Node * ptr;
            struct Node * preptr;
            ptr = head -> next;
            preptr = head;

            while(preptr -> data != afterNode) {
                ptr = ptr -> next;
                preptr = preptr -> next;
            }
            preptr -> next = ptr -> next;
            free(ptr);
            printf("A node has been deleted. \n");
        }
        else printf("The node is not present in the linked list, try again.");
    }
}

void deleteBefore() {
    if(head == NULL) printf("Create a linked list first");
    else {
        int beforeNode;
        printf("Enter the node to be deleted before: ");
        scanf("%d", &beforeNode);

        int check = isPresent(beforeNode);
        if(check == 1) {
            printf("A node has been deleted. \n");

            struct Node * ptr;
            struct Node * preptr;
            ptr = head -> next;
            preptr = head;

            while(ptr -> next -> data != beforeNode) {
                ptr = ptr -> next;
                preptr = preptr -> next;
            }
            preptr -> next = ptr -> next;
            free(ptr);
        }
        else printf("The node is not present in the linked list, try again.");
    }
}

void deleteSpecific() {
    if(head == NULL) printf("Create a linked list first");
    else {
        int specificNode;
        printf("Enter the node to be deleted: ");
        scanf("%d", &specificNode);

        int check = isPresent(specificNode);
        if(check == 1){
            printf("A node has been deleted. \n");

            struct Node * ptr;
            struct Node * preptr;
            ptr = head -> next;
            preptr = head;

            while(ptr -> data != specificNode) {
                ptr = ptr -> next;
                preptr = preptr -> next;
            }
            preptr -> next = ptr -> next;
            free(ptr);
        }
        else printf("The node is not present in the linked list, try again.");
    }
}

void displayNodes() {
    if(head == NULL) printf("Create a linked list first");
    else {
        struct Node * ptr;
        ptr = head;

        while(ptr != NULL){
            printf("%d, ", ptr -> data);
            ptr = ptr -> next;
        }
        printf("\n\n");
    }
}

void menu() {
    while(1){
    int choice;
        printf("\n\n1: Create a new linked list. \n2: Insert a node at beginning. \n3: Insert a node at the end. \n4: Insert a node after a node. \n5: Insert a node before a node. \n6: Insert a node at an index. \n7: Delete a node at beginning. \n8: Delete a node at the end. \n9: Delete a node after a node. \n10: Delete a node before a node. \n11: Delete a specific node. \n12: Display the Linked List. \n13: Exit. \n\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1: createLinkedList();
            break;
        case 2: insertAtBeg();
            break;
        case 3: insertAtEnd();
            break;
        case 4: insertAfter();
            break;
        case 5: insertBefore();
            break;
        case 6: insertAtIndex();
            break;
        case 7: deleteAtBeg();
            break;
        case 8: deleteAtEnd();
            break;
        case 9: deleteAfter();
            break;
        case 10: deleteBefore();
            break;
        case 11: deleteSpecific();
            break;
        case 12: displayNodes();
            break;
        case 13: exit(0);
            break;
        default: printf("Enter a valid choice");
        }
    }
}
 
int main() {
    menu();
    return 0;
}