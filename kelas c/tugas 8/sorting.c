#include <stdio.h>

int main() {
    int arr[] = {54, 23, 12, 56, 78, 50, 12, 89, 12};
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        for (int j = size-1; j > i; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}