#include <stdio.h>
#include <stdlib.h>

struct data {
    char IndeksNilai;
    int SKS;
};

int konversi(char nilai, int* nilaiKonversi);

int main() {
    int M, n;
    int jumSKS = 0, jumNilai = 0;
    
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &M);
    printf("Masukkan jumlah mata kuliah: ");
    scanf("%d", &n);

    struct data NilaiMhs[M][n];
    float NR[n];

    for (int i = 0; i < M; i++) {
        printf("\nMahasiswa ke-%d\n", i+1);
        for (int j = 0; j < n; j++) {
            printf("Masukkan nilai mata kuliah %d: ", j+1);
            getchar();
            NilaiMhs[i][j].IndeksNilai = getchar();
            char nilai = NilaiMhs[i][j].IndeksNilai;
            int nilaiKonversi = 0;
            konversi(nilai, &nilaiKonversi);
            printf("Masukkan Jumlah SKS: ");
            scanf("%d", &NilaiMhs[i][j].SKS);
            jumNilai += nilaiKonversi*NilaiMhs[i][j].SKS;
            jumSKS += NilaiMhs[i][j].SKS;
        }
        NR[i] = (float)jumNilai / (float)jumSKS;
    }
    printf("\nNIlai rata-rata (IP) Mahasiswa: \n");
    for (int i = 0; i < M; i++){
        printf("Nilai rata-rata (IP) Mahasiswa %d adalah %.1f\n", i+1, NR[i]);
    }
    return 0;
}

int konversi(char nilai, int* nilaiKonversi) {
    switch (nilai) {
        case 'A':
            *nilaiKonversi = 4;
            break;
        case 'B':
            *nilaiKonversi = 3;
            break;
        case 'C':
            *nilaiKonversi = 2;
            break;
        case 'D':
            *nilaiKonversi = 1;
            break;
        case 'E':
            *nilaiKonversi = 0;
            break;
        default:
            printf("Nilai tidak valid\n");
            exit(1);
    }
}