/*
  Muh. Shobur Fattah
  D121211088
  BAB 17 NO 7
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Arsip1 {
  int NIM;
  char nama[26];
  char alamat[26];
  int noTelp;
};

struct Arsip2 {
  int NIM;
  char gender;
  float IP;
};

struct Arsip3 {
  int NIM;
  char nama[26];
  float IP;
};

int main() {
  int menu;
  struct Arsip1 arsip1;
  struct Arsip2 arsip2;
  struct Arsip3 arsip3;

  do {
    printf("\nPilih menu:\n1. tulis arsip 1\n2. tulis arsip 2\n3. tampilkan arsip 1\n4. tampilkan arsip 2\n5. exit\n");
    scanf("%d", &menu);
    printf("\n");
    if (menu == 1) {
      // isi arsip1
      FILE *fileArsip1 = fopen("arsip1_97.bin", "ab");

      printf("NIM: "); scanf("%d", &arsip1.NIM);
      while (arsip1.NIM != 9999) {
        fflush(stdin);
        printf("Nama: "); gets(arsip1.nama);
        printf("Alamat: "); gets(arsip1.alamat);
        printf("No HP: "); scanf("%d", &arsip1.noTelp);
        fwrite(&arsip1, sizeof(arsip1), 1, fileArsip1);
        printf("NIM: "); scanf("%d", &arsip1.NIM);
      }
      fclose(fileArsip1);
    } else if (menu == 2) {
      // isi arsip2
      FILE *fileArsip2 = fopen("arsip2_97.bin", "ab");

      printf("NIM: "); scanf("%d", &arsip2.NIM);
      while (arsip2.NIM != 9999) {
        fflush(stdin);
        printf("Kelamin: "); scanf("%c", &arsip2.gender);
        printf("IP: "); scanf("%f", &arsip2.IP);
        fwrite(&arsip2, sizeof(arsip2), 1, fileArsip2);
        printf("NIM: "); scanf("%d", &arsip2.NIM);
      }
      fclose(fileArsip2);
    } else if (menu == 3) {
      // tampilkan arsip1
      FILE *fileArsip1 = fopen("arsip1_97.bin", "rb");
      printf("NIM\t\tNAMA\t\tALAMAT\t\tNO HP\n");
      fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
      while (!feof(fileArsip1)) {
        printf("%d\t\t%s\t\t%s\t\t%d\n", arsip1.NIM, arsip1.nama, arsip1.alamat, arsip1.noTelp);
        fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
      }
      fclose(fileArsip1);
      printf("\n");
    } else if (menu == 4) {
      // tampilkan arsip2
      FILE *fileArsip2 = fopen("arsip2_97.bin", "rb");
      printf("NIM\t\tKELAMIN\t\tIP\n");
      fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
      while (!feof(fileArsip2)) {
        printf("%d\t\t%c\t\t%.2f\n", arsip2.NIM, arsip2.gender, arsip2.IP);
        fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
      }
      fclose(fileArsip2);
      printf("\n");
    }  else if (menu == 6) {
      // menggabungkan arsip1 & arsip2 ke arsip3
      FILE *fileArsip1 = fopen("arsip1_97.bin", "rb");
      FILE *fileArsip3 = fopen("arsip3_97.bin", "wb");

      fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
      printf("Membaca arsip1\n");
      while (!feof(fileArsip1)) {

        FILE *fileArsip2 = fopen("arsip2_97.bin", "rb");
        fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
        printf("Membaca arsip2\n");
        while (!feof(fileArsip2)) {
          if (arsip1.NIM == arsip2.NIM) {
            arsip3.NIM = arsip1.NIM;
            strcpy(arsip3.nama, arsip1.nama);
            arsip3.IP = arsip2.IP;

            fwrite(&arsip3, sizeof(arsip3), 1, fileArsip3);
            printf("Mengisi arsip3\n");
            break;
          }
          fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
          printf("looping di arsip2\n");
        }
        fclose(fileArsip2);
        fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
        printf("Membaca arsip1\n");
      }
      
      printf("\nfile arsip 3 telah terisi\n");
      fclose(fileArsip1);
      fclose(fileArsip3);

    } else if (menu == 7) {
      // tampilkan arsip3
      FILE *fileArsip3 = fopen("arsip3_97.bin", "rb");

      printf("NIM\t\tNAMA\t\tIP\n");
      fread(&arsip3, sizeof(arsip3), 1, fileArsip3);
      while (!feof(fileArsip3)) {
        printf("%d\t\t%s\t\t%.2f\n", arsip3.NIM, arsip3.nama, arsip3.IP);
        fread(&arsip3, sizeof(arsip3), 1, fileArsip3);
      }

      fclose(fileArsip3);
      printf("\n");
    }else if (menu != 5) {
      printf("Pilihan tidak ada!\n");
    }
  } while (menu !=5);

  printf("KELUAR DARI PROGRAM\n");
  return 0;
}