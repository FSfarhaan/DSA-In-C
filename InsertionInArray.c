// This is a program to insert an Element in an Array at a particulat Index;

#include <stdio.h>

// Inserting an element at an index;
void insertElement(int arr[], int element, int index, int size){
    for(int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}

// To display the contents of array;
void displayArray(int arr[], int size){
    for(int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
 
int main() {

    // Initializing an array;
    int myArr[10] = {1, 4, 67, 45, 33, 100};


    // Specifying the element to be inserted at an index, along with the size of the array used;
    int index = 2, element = 55, usedSize = 6;

    printf("Array before Insertion: \n");
    displayArray(myArr, usedSize);

    printf("Array After Insertion: \n");
    usedSize++;
    insertElement(myArr, element, index, usedSize);
    displayArray(myArr, usedSize);

    return 0;
}