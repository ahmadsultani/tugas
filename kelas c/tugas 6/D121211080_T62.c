#include <stdio.h>

const char* CekTriple(int a, int b, int c) {
    if (c*c == a*a + b*b) return "triple phytagoras";
    else return "bukan triple phytagoras";
}

int main() {
    int a, b, c;
    printf("Masukkan 3 sisi segitiga dari kecil ke besar: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("%d, %d, dan %d %s", a, b, c, CekTriple(a, b, c));
    return 0;
}