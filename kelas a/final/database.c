#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30
typedef struct  {
    char nama[40];
    char email[40];
    char notelp[40];
} Contact;
typedef struct {
    Contact contacts[SIZE];
} hashTable;

int hash(int);
void initHashTable(hashTable*);
int getKey(char*);
int linearrehash(hashTable*, int);
void addData(hashTable*);
void removeData(hashTable*);
void editData(hashTable*);
int search(hashTable*, char*);
void searchData(hashTable);
void printHashTable(hashTable);
int Choose();

Contact temp;

int main() {
    hashTable ht;
    initHashTable(&ht);
    int choose = Choose();

    while (choose != 5) {
        switch (choose) {
            case 1:
                addData(&ht);
            break;
            case 2:
                removeData(&ht);
            break;
            case 3:
                editData(&ht);
            break;
            case 4:
                searchData(ht);
            break;    
            default:
                printf("Pilihan tidak valid!\n");
        }
        printf("\nTekan Enter untuk melanjutkan ");
        getchar();
        system("cls");
        choose = Choose();
    }
    printf("Selesai\n");
    return 0;
}

int Choose() {
    int chosen;
    printf("Database Kontak\n");
    printf("1. Tambah Kontak\n");
    printf("2. Hapus Kontak\n");
    printf("3. Edit Kontak\n");
    printf("4. Cari Kontak\n");
    printf("5. Keluar\n");
    printf("Pilih (1-5): ");
    scanf("%d", &chosen);
    fflush(stdin);
    return chosen;
}

int hash(int key) {
    return key % SIZE;
}

int linearrehash(hashTable* ht, int address) {
    int trackIndex = 0;
    while(strcmp(ht->contacts[address].notelp, "\0") != 0 && trackIndex <= SIZE) {
        address = hash(address+1);
        trackIndex++;
    }
    if (trackIndex > SIZE) return -1;
    else return address;
}

void initHashTable(hashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        strcpy(ht->contacts[i].nama, "\0");
        strcpy(ht->contacts[i].email, "\0");
        strcpy(ht->contacts[i].notelp, "\0");
    }
}

int getKey(char* str) {
    int count = 0, index = 0;
    while (str[index] != '\0') {
        count += str[index];
        index++;
    }
    return count;
}

void input() {
    fflush(stdin);
    printf("Nama: "); scanf("%[^\n]", temp.nama); 
    fflush(stdin);
    printf("Email: "); scanf("%[^\n]", temp.email);
    fflush(stdin);
    printf("No. Telepon: "); scanf("%[^\n]", temp.notelp);
    fflush(stdin);
}

void addData(hashTable* ht) { 
    int key, index, trackIndex;
    system("cls");
    printf("Menambah Kontak\n");
    input();
    key = getKey(temp.notelp);
    index = hash(key);
    index = linearrehash(ht, index);
    if (index == -1) {
        printf("Kontak penuh!\n");
    } else {
        strcpy(ht->contacts[index].nama, temp.nama);
        strcpy(ht->contacts[index].email, temp.email);
        strcpy(ht->contacts[index].notelp, temp.notelp);
        printf("Kontak berhasil ditambah\n");
    }
}

void removeData(hashTable* ht) {
    char* str = malloc(40);
    system("cls");
    printf("Masukkan nomor telepon kontak yang ingin dihapus: ");
    scanf("%[^\n]", str);
    fflush(stdin);
    int index = search(ht, str);
    if (index == -1) printf("\nKontak tidak ditemukan\n"); 
    else {
        strcpy(ht->contacts[index].nama, "\0");
        strcpy(ht->contacts[index].email, "\0");
        strcpy(ht->contacts[index].notelp, "\0");
        printf("\nKontak berhasil dihapus\n");
    }
}

int search(hashTable* ht, char* notelp) {
    int address = hash(getKey(notelp));
    int trackIndex = 0;
    while (strcmp(ht->contacts[address].notelp, notelp) != 0 && trackIndex <= SIZE) {
        address = hash(address+1);
        trackIndex++;
    }
    if (trackIndex > SIZE) return -1;
    else return address; 
}

void searchData(hashTable ht) {
    char* str = malloc(40);
    system("cls");
    printf("Masukkan nomor telepon kontak yang ingin dicari: ");
    scanf("%[^\n]", str);
    fflush(stdin);
    int index = search(&ht, str);
    if (index == -1) {
        printf("\nKontak tidak ditemukan!\n");
    } else {
        printf("\nKontak ditemukan pada urutan ke-%d\n", index+1);
        printf("Nama: %s\n", ht.contacts[index].nama);
        printf("Email: %s\n", ht.contacts[index].email);
        printf("Nomor Telepon: %s\n", ht.contacts[index].notelp);
    }
}

void editData(hashTable* ht) {
    char* notelp = malloc(40);
    system("cls");
    printf("Masukkan nomor telepon kontak yang ingin diedit: ");
    scanf("%[^\n]", notelp);
    fflush(stdin);
    int index = search(ht, notelp);
    if (index == -1) {
        printf("\nKontak tidak ditemukan\n");
        return;
    } 
    printf("\nMengedit Kontak\n");
    input();
    strcpy(ht->contacts[index].nama, temp.nama);
    strcpy(ht->contacts[index].email, temp.email);
    strcpy(ht->contacts[index].notelp, temp.notelp);
    printf("Berhasil mengedit kontak\n");
}