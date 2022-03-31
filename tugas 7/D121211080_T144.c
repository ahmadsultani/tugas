#include <stdio.h>

int main() {
    int m, n;
    printf("Masukkan jumlah baris dan kolom matriks (m n): ");
    scanf("%d %d", &m, &n);
    char C[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Masukkan nilai matriks C[%d][%d]: ", i, j);
            scanf("%c", &C[i][j]);
        }
    }

    int jumA = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (C[i][j] == 'a' || C[i][j] == 'A') {
                jumA++;
            }
        }
    }

    printf("Jumlah huruf a: %d\n", jumA);
    return 0;
}