// Program to Search an element in an array using Binary Search;

#include <stdio.h>

int binSearch(int arr[], int element, int size){
    int beg = 0, end = size, mid;

    while(beg <= end){
        mid = (beg + end) / 2;
        if(arr[mid] == element) return mid;
        else if (arr[mid] < element) beg = mid + 1;
        else end = mid - 1;
    }
    return -1;
}
 
int main() {

    // Initializing an array;
    int myArray[10] = {1, 4, 10, 23, 56, 234, 332, 500, 767, 1239};

    // Specifying the element to be found along with the array size;
    int element = 500; int size = 10;

    // Catching the index at which the element is found;
    int atIndex = binSearch(myArray, element, size);
    if(atIndex == -1) printf("The element is not in the array");
    else printf("The element was found at index %d", atIndex);

    return 0;
}