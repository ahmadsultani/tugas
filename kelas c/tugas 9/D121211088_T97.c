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
  struct Arsip1 arsip1;
  struct Arsip2 arsip2;
  struct Arsip3 arsip3;

  // menampilkan isi dari arsip pertama
  printf("Menampilkan isi dari arsip pertama:\n");
  FILE *fileArsip1 = fopen("arsip1_97.bin", "rb");
  printf("NIM\t\tNAMA\t\tALAMAT\t\tNO HP\n");
  fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
  while (!feof(fileArsip1)) {
    printf("%d\t\t%s\t\t%s\t\t%d\n", arsip1.NIM, arsip1.nama, arsip1.alamat, arsip1.noTelp);
    fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
  }
  fclose(fileArsip1);
  printf("\n");

  // menampilkan isi dari arsip kedua
  printf("Menampilkan isi dari arsip kedua:\n");
  FILE *fileArsip2 = fopen("arsip2_97.bin", "rb");
  printf("NIM\t\tKELAMIN\t\tIP\n");
  fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
  while (!feof(fileArsip2)) {
    printf("%d\t\t%c\t\t%.2f\n", arsip2.NIM, arsip2.gender, arsip2.IP);
    fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
  }
  fclose(fileArsip2);
  printf("\n");

  // membuat arsip baru dari irisan arsip pertama dan kedua
  fileArsip1 = fopen("arsip1_97.bin", "rb");
  FILE *fileArsip3 = fopen("arsip3_97.bin", "wb");

  fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
  while (!feof(fileArsip1)) {

    fileArsip2 = fopen("arsip2_97.bin", "rb");
    fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
    while (!feof(fileArsip2)) {
      if (arsip1.NIM == arsip2.NIM) {
        arsip3.NIM = arsip1.NIM;
        strcpy(arsip3.nama, arsip1.nama);
        arsip3.IP = arsip2.IP;

        fwrite(&arsip3, sizeof(arsip3), 1, fileArsip3);
        break;
      }
      fread(&arsip2, sizeof(arsip2), 1, fileArsip2);
    }
    fclose(fileArsip2);
    fread(&arsip1, sizeof(arsip1), 1, fileArsip1);
  }
  fclose(fileArsip1);
  fclose(fileArsip3);

  // menampilkan isi arsip 3
  fileArsip3 = fopen("arsip3_97.bin", "rb");

  printf("NIM\t\tNAMA\t\tIP\n");
  fread(&arsip3, sizeof(arsip3), 1, fileArsip3);
  while (!feof(fileArsip3)) {
    printf("%d\t\t%s\t\t%.2f\n", arsip3.NIM, arsip3.nama, arsip3.IP);
    fread(&arsip3, sizeof(arsip3), 1, fileArsip3);
  }

  fclose(fileArsip3);
  printf("\n");
}