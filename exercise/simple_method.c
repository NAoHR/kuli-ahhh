#include <stdio.h>
#include <stdlib.h>

void print_segitiga(int count) {
    for(int i = 0; i <= count; i++) {
        for(int j=0; j < i; j++) {
            if(i == count) {
                printf("*");
                continue;
            }
            if(j == 0 || j == i-1) {
                printf("*");
            }else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int validasi_value(int count) {
    if(count <=0) {
        printf("Maaf, angka tidak boleh kurang dari sama dengan 0\n");
        return 0;
    }
    return 1;
}

void main() {
    int counter;
    int is_valid = 0;
    
    do {

        printf("Masukkan Jumlah: ");
        scanf("%d", &counter);
        is_valid = validasi_value(counter);

    }while(is_valid == 0);

    print_segitiga(counter);
}