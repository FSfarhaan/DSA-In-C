// This is a program to delete an Element in an Array at a particular Index;

#include <stdio.h>

// Deleting an element at an index;
void deleteElement(int arr[], int index, int size){
    for(int i = index; i < size; i++) {
        arr[i] = arr[i + 1];
    }
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

    // Specifying the index to be deleted, along with the size of the array used;
    int index = 4, usedSize = 6;

    printf("Array before Deletion: \n");
    displayArray(myArr, usedSize);

    printf("Array After Deletion: \n");
    usedSize--;
    deleteElement(myArr, index, usedSize);
    displayArray(myArr, usedSize);

    return 0;
}