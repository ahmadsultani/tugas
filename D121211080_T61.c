#include <stdio.h>

void bunga(long long int A, long long int i, long long int n, float *F) {
    float x = 1.0+(i/100.0);
    float sum = 0;
    for (int j=1; j<=n; j++){
        sum += x;
        x = x * (1.0+(i/100.0));
    }
    *F = (float)A*sum;
}

int main() {
    long long int uang, bungaTahunan, tahun;
    float hasilTabungan;
    printf("Masukkan tabungan awal: ");
    scanf("%lld", &uang);
    printf("Masukkan besar bunga: ");
    scanf("%lld", &bungaTahunan);
    printf("Masukkan jumlah tahun: ");
    scanf("%lld", &tahun);

    bunga(uang, bungaTahunan, tahun, &hasilTabungan);
    printf("Jumlah tabungan setelah %lld tahun adalah:\nRp. %.0f", tahun, hasilTabungan);
    return 0;
}