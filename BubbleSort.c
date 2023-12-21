// Program to sort an array using Bubble sort;

#include <stdio.h>

void bubbleSort(int arr[]) {
    int flag = 1;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            } 
        }
        if(flag) return;
    }
}

void displayArr(int arr[]) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 
int main() {
    int arr[10] = {2, 34, 21 , 324, 31, 30, 12, 440, 3450, 1};

    printf("Before Sorting: \n");
    displayArr(arr);

    printf("After Sorting: \n");
    bubbleSort(arr);
    displayArr(arr);
    
    return 0;
}