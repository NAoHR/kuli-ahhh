#include <stdio.h>
#include <stdlib.h>


int main() {
    /*
      Write a program to receive a string entered by the user, 
      and then save the string into a file with the name also given by the user.
    */

    FILE* fptr;
    char nama[255];
    char nama_file[100];

    // input nama file
    printf("Masukkan nama file: ");
    fgets(nama_file, sizeof(nama_file), stdin);

    // memasukkan nama yang ingin ada di dalam file
    printf("Masukkan isi file: ");
    fgets(nama, sizeof(nama), stdin);

    // membuka file
    fptr = fopen(nama_file, "w+");

    if(fptr == NULL) {
        printf("unable to open file");
        return 1;
    }

    // isi file
    printf("writing to file\n");
    fputs(nama, fptr);

    fclose(fptr);

    printf("success to create file name %s\n", nama_file);

}