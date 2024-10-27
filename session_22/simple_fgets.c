#include <stdio.h>


int main() {
    char buffer[255];

    printf("Masukkan Alamat Anda: ");
    if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("Anda Tinggal Di: %s", buffer);
    }else {
        printf("Gagal Dalam Membaca Input");
        return 1;
    }

    return 0;
}