#include <stdio.h>

void ReadArrArr(int arr[], int size) {
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
    int A[5], B[5], C[5];
    int D[3][5];
    float RATA = 0;
    int data;
    printf("Masukkan Data A:\n");
    ReadArr(A, 5);
    printf("Masukkan Data B:\n");
    ReadArr(B, 5);
    printf("Masukkan Data C:\n");
    ReadArr(C, 5);     
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
    PrintArr(A, 5);
    printf("\nB : ");
    PrintArr(B, 5);
    printf("\nC : ");
    PrintArr(C, 5);
    printf("\nMatriks D:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 5; col++) {
            printf("%d ", D[row][col]);
        }
        printf("\n");
    }
    RATA = RATA / (5 * 3);
    printf("\nrata-rata: %g", RATA);
    return 0;
}