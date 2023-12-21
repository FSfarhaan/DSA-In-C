#include <stdio.h>

void selectionSort(int arr[]) {
    int indexOfMin, temp;
    for(int i = 0; i < 10; i++) {
        indexOfMin = i;
        for(int j = i + 1; j < 10; j++) {
            if(arr[j] < arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = arr[indexOfMin];
        arr[indexOfMin]  = arr[i];
        arr[i] = temp;
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
    selectionSort(arr);
    displayArr(arr);
    
    return 0;
}