#include <stdio.h>

static int jumlah_murid = 0;

void tambah_murid(void) {
    jumlah_murid++;
}

void main() {
    for(int i = 0; i < 30; i++) {
        tambah_murid();
    }

    printf("total murid adalah %d\n", jumlah_murid);
}