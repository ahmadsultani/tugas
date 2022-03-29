#include <stdio.h>

void balikElemen(char A[], int n){
    char temp = A[n-1];
    A[n-1] = A[0];
    A[0] = temp; 
}

int main() {
    int n;
    printf("Masukkan jumlah huruf: ");
    scanf("%d", &n);
    fflush(stdin);
    char A[n];
    printf("Masukkan kata: ");
    scanf("%s", A);
    printf("Kata sebleum ditukar: %s", A);
    balikElemen(A, n);
    printf("Kata setelah ditukar: %s", A);
    return 0;
}