#include <stdio.h>
#include <stdlib.h>

struct data {
    char IndeksNilai;
    int SKS;
};

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
            printf("Masukkan Nilai Mata Kuliah %d: ", j+1);
            getchar();
            NilaiMhs[i][j].IndeksNilai = getchar();
            int nilaiKonversi = 0;
            switch (NilaiMhs[i][j].IndeksNilai){
                case 'A': case 'a':
                    nilaiKonversi = 4;
                    break;
                case 'B': case 'b':
                    nilaiKonversi = 3;
                    break;
                case 'C': case 'c':
                    nilaiKonversi = 2;
                    break;
                case 'D': case 'd':
                    nilaiKonversi = 1;
                    break;
                case 'E': case 'e':
                    nilaiKonversi = 0;
                    break;
                default:
                    printf("Nilai tidak valid\n\n");
                    system("clear");
                    system("cls");
                    return main();
            }
            printf("Masukkan Jumlah SKS: ");
            scanf("%d", &NilaiMhs[i][j].SKS);
            jumNilai += nilaiKonversi*NilaiMhs[i][j].SKS;
            jumSKS += NilaiMhs[i][j].SKS;
        }
        NR[i] = (float)jumNilai / (float)jumSKS;
    }
    for (int i = 0; i < M; i++){
        printf("Nilai rata-rata (IP) Mahasiswa %d adalah %.1f\n", i+1, NR[i]);
    }
    return 0;
}