#include <stdio.h>

void CountingSort(int*, int, int, int);

int main() {
    int L[] = {54, 23, 12, -1, 56, 78, 50, 12, 89, 12};
    int N = 10, NilaiMin = -1, NilaiMaks = 89;
    CountingSort(L, N, NilaiMin, NilaiMaks);
    printf("\nLarik L setelah diurutkan menaik: \n");
    for(int i = 0; i < N; i++){
        printf("%d ", L[i]);
    }
    return 0;
}

void CountingSort(int* arr, int N, int min, int max){
    int range = max - min + 1;
    int count[range];
    int result[N];

    for (int i = 0; i < range; i++){ //untuk bahasa C agar variable 
        count[i] = 0;                  //tidak berisi nilai sebarang
    }
    for (int i = 0; i < N; i++) {
        count[arr[i]-min]++;
    }
    for (int i = 1; i < range; i++) { 
        count[i] += count[i-1];
    }
    for (int i = range-1; i > 0; i--) {
        count[i] = count[i-1];
    }
    count[0] = 0; //elemen pertama dimulai dari indeks 0
    for (int i = 0; i < N; i++) {
        result[count[arr[i]-min]] = arr[i];
        count[arr[i]-min]++; //mengubah awal indeks elemen bernilai arr[i]
    }
}