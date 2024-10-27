#include <stdio.h>

int main() {

    FILE *file = fopen("testing.txt", "w"); // membuka file bernama testing.txt dengan tipe write (create apabila tidak ada)
    
    if(file == NULL) { // error handling bila gagal
        perror("Gagal Membuka File");
        return 1;
    }

    char name[100]; // inisiasi char name
    
    printf("Masukkan Nama Anda: ");
    if(fgets(name, sizeof(name), stdin) == NULL) { // fgets untuk mendapat input dari terminal
        perror("Gagal Menerima Input");
        fclose(file);
        return 1;
    }

    // fputs digunakan untuk memasukkan isi dari name ke file
    if(fputs(name, file) == EOF) {
        perror("Gagal untuk Menulis File"); // error handling
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("Berhasil Untuk Menulis File");



}