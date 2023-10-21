#include <stdio.h>

int linSearch(int arr[], int element, int size) {
    for(int i = 0; i < size; i++){
        if(arr[i] == element) return i;
    }
    return -1;
}
 
int main() {

    // Initializing an Array;
    int myArr[10] = {1, 45, 64, 23, 7574, 324, 867, 56, 232, 10};

    // Speciying the element and the size of the array'
    int element = 324, size = 10;

    int atIndex = linSearch(myArr, element, size);
    if(atIndex == -1) printf("The element is not in the array");
    else printf("The element was found at index %d", atIndex);

    return 0;
}