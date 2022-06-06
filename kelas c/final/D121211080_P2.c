#include <stdio.h>

int fibonacci(int n) {
    int fib1 = 0, fib2 = 1, nth_fib;
    for (int i = 0; i <= n; i++) {
        nth_fib = fib1;
        fib1 = fib2;
        fib2 = nth_fib + fib2;
    }
    return nth_fib;
}

int factorial(int n) {
    if (n < 0) return -1;
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
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
            printf("%d ",fibonacci(i));            
        }
        printf("\n");

        do {
            printf("Apakah anda ingin melanjutkan (Y/N)? ");
            scanf("%c", &lanjut);
            fflush(stdin);
        } while(lanjut != 'Y' && lanjut != 'N');

    } while (lanjut == 'Y');
    printf("Selesai\n");
}