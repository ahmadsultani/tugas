#include <stdio.h>

int factorial(int n) {
    //base case
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int fibbonacci(int n) {
    if(n == 0){
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return (fibbonacci(n-1) + fibbonacci(n-2));
    }
}

int main() {
    int n, i;
    char lanjut;
    do {
        printf("Masukkan angka: ");
        scanf("%d", &n);
        fflush(stdin);
        printf("Factorial of %d: %d\n" , n , factorial(n));
        printf("Fibbonacci of %d: " , n);
        
        for(i = 0;i < n;i++) {
            printf("%d ",fibbonacci(i));            
        }
        printf("\n");

        do {
            printf("Apakah anda ingin melanjutkan (Y/N)? ");
            scanf("%c", &lanjut);
            fflush(stdin);
        } while(lanjut != 'Y' && lanjut != 'N');

    } while (lanjut == 'Y');
    printf("Selesai");
}