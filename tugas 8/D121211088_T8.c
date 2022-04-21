/*
  Muh. Shobur Fattah
  D121211088
  BAB 16 NO 8
*/
#include <stdio.h>
#include <stdlib.h>

const int NilaiMin = 1;
const int NilaiMax = 21;

void countSort(int L[], int n) {
  int *count = (int*) calloc(NilaiMax, sizeof(int));
  int j=0;
  int k=0;

  // looping untuk mengisi nilai count
  for (int i=0; i<NilaiMax; i++) {
    if (i == n) break;  // keluar dari looping jika telah sampai di akhir array L

    count[L[i]]++;  // menambah isi count[L[i]] dengan 1
  }
  
  
  // mengisi array L dengan count
  while (n > 0) {  // looping dijalankan selama masih terdapat elemen yang belum dipindahkan
    while (count[j] != 0) {
      L[k] = j;
      count[j]--;
      k++;
      n--;
    }
    j++;
  }  // count[j] isinya 0
}

int main() {
  int n;
  printf("Masukkan banyak data: "); 
  scanf("%d", &n);
  int *L = (int*) calloc(n, sizeof(int));

  printf("\nNilai Minimal : 1\nNilai Maksimal : 20\n\n");
  for (int i=0; i<n; i++) {
    printf("Data %d: ", i+1); scanf("%d", &L[i]);
  }

  countSort(L, n);

  // cetakArray(L, n);
  printf("\nData Setelah count sort:\n");
  for (int i=0; i<n; i++) {
    printf("Data %d: %d\n", i+1, L[i]);
  }
}