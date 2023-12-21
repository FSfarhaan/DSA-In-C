#include <stdio.h>

void insertionSort(int arr[]){
    int i, j, key;
    for(i = 1; i < 10; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr);
    displayArr(arr);
    
    return 0;
}