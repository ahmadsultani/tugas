#include <stdio.h>

void ReadArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}
        
void PrintArr(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int A[n], B[n], C[n];
    int D[3][n];
    float RATA = 0;
    int data;
    printf("Masukkan Data A:\n");
    ReadArr(A, n);
    printf("Masukkan Data B:\n");
    ReadArr(B, n);
    printf("Masukkan Data C:\n");
    ReadArr(C, n);     
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 5; col++){
            switch (row) {
                case 0:
                    data = A[col];
                    break;
                case 1:
                    data = B[col];
                    break;
                case 2:
                    data = C[col];
                    break;
            }
            D[row][col] = data;
            RATA += data;
        }
    }
    printf("\nA : ");
    PrintArr(A, n);
    printf("\nB : ");
    PrintArr(B, n);
    printf("\nC : ");
    PrintArr(C, n);
    printf("\nMatriks D:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < n; col++) {
            printf("%d ", D[row][col]);
        }
        printf("\n");
    }
    RATA = RATA / (n * 3);
    printf("\nrata-rata: %g", RATA);
    return 0;
}