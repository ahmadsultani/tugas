#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nama[30];
    char alamat[30];
    char telpon[15];
    char email[30];
} Contact;

Contact contacts[30];

int main(){
    int pilih, last_index = -1;
    char lanjut;
    do {
        system("cls");
        printf("Database Kontak Kelas A\n");
        printf("=========================\n");
        printf("1. Tambah Kontak\n");
        printf("2. Tampilkan Kontak\n");
        printf("3. Keluar\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        switch (pilih) {
            case 1:
                last_index++;
                printf("\nMenambah Kontak\n");
                printf("====================\n");
                printf("Nama : ");
                fflush(stdin);
                scanf("%[^\n]", contacts[last_index].nama);
                printf("Alamat : ");
                fflush(stdin);
                scanf("%[^\n]", contacts[last_index].alamat);
                printf("No. Telpon : ");
                fflush(stdin);
                scanf("%[^\n]", contacts[last_index].telpon);
                printf("Email : ");
                fflush(stdin);
                scanf("%[^\n]", contacts[last_index].email);
                break;
            case 2:
                printf("\nTampilkan Kontak\n");
                printf("====================\n");
                for (int i = 0; i <= last_index; i++) {
                    printf("Nama : %s\n", contacts[i].nama);
                    printf("Alamat : %s\n", contacts[i].alamat);
                    printf("No. Telpon : %s\n", contacts[i].telpon);
                    printf("Email : %s\n", contacts[i].email);
                    printf("\n");
                }
                printf("Lanjut? ");
                fflush(stdin);
                scanf("%c", &lanjut); 
                break;
            case 3:
                break;
            default: 
                printf("Invalid\n");
        }
    } while(pilih != 3);
    printf("Selesai\n");
    return 0;
}