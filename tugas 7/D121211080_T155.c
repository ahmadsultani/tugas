#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int left = 0, right = sizeof(arr)/sizeof(arr[0]) - 1;
    int target = 1;
    while (left != right || arr[left] != arr[right]) {
        int mid = left + (right-left)/(arr[right]-arr[left]) * (target-arr[left]);
        if (arr[mid] == target) {
            printf("Target terletak pada indeks ke-%d\n", mid);
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}