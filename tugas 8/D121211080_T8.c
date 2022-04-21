#include <stdio.h>

void CountingSort(int*, int, int, int);

int main() {
    int N, NilaiMin, NilaiMaks;
    printf("Masukkan jumlah data: ");
    scanf("%d", &N);
    int L[N];
    printf("Masukkan data sejumlah %d: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
        if (i == 0) {
            NilaiMin = L[i];
            NilaiMaks = L[i];
        } 
        else if (NilaiMin > L[i]) {
            NilaiMin = L[i];
        } 
        else if (NilaiMaks < L[i]) {
            NilaiMaks = L[i];
        }
    }

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

    for (int i = min; i < range; i++){ //untuk bahasa C agar variable 
        count[i] = 0;                  //tidak berisi nilai sebarang
    }
    for (int i = 0; i < N; i++) {
        count[arr[i]-min]++;
    }
    for (int i = min+1; i < range; i++) {
        count[i] += count[i-1];
    }
    for (int i = range-1; i > min; i--) {
        count[i] = count[i-1];
    }
    for (int i = 0; i < N; i++) {
        result[count[arr[i]-min]] = arr[i];
        count[arr[i]-min]++; //mengubah awal indeks elemen bernilai arr[i]
    }
    for (int i = 0; i < N; i++) {
        arr[i] = result[i];
    }
}