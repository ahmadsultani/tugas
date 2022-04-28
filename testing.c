#include <stdio.h>

void InsertionSort(int arr[], int size){
    int i, j, temp;
    for(i = 1; i < size; i++){
        temp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > temp; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int i, j;
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}