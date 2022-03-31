#include <stdio.h>

int interpolation_search(int arr[], int N, int target){
    int left = 0, right = N - 1;
    while (left != right || arr[left] != arr[right]) {
        int mid = left + (right-left)/(arr[right]-arr[left]) * (target-arr[left]);
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; //target tidak ditemukan
}

int main() {
    int N, target, index;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        printf("Masukkan elemen ke-%d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Masukkan target pencarian: ");
    scanf("%d", &target);
    index = interpolation_search(arr, N, target);
    if (index == -1) printf("Target tidak ditemukan\n");
    else printf("Target ditemukan pada index %d\n", index);
    return 0;
}