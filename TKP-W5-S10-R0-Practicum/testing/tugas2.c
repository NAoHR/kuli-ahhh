#include <stdio.h>

void main() {
    // masukkan 5 nilai
    // tertinggi
    // terendah
    // rata rata

    
    // masukkan 5 nilai
    // array = [a,b,c,d]
    int counter = 5;
    int nilai[5];
    int *ptr = nilai; // address memori pada index pertama di array nilai
    
    int nilai_terendah;
    int nilai_tertinggi;
    int total_nilai = 0;

    for(int i = 0; i < counter; i++) {
        printf("Masukkan nilai ke %d: ", (i + 1));
        scanf("%d", (ptr + i));
        int nilai_saat_ini = *(ptr + i);
        
        if(i == 0) {
            nilai_terendah = nilai_saat_ini;
            nilai_tertinggi = nilai_saat_ini;
        }

        if(nilai_saat_ini < nilai_terendah) {
            nilai_terendah = nilai_saat_ini;
        }else if(nilai_saat_ini > nilai_tertinggi) {
            nilai_tertinggi = nilai_saat_ini;
        }
        total_nilai += nilai_saat_ini;
    }

    printf("nilai terendah: %d\n", nilai_terendah);
    printf("nilai tertinggi: %d\n", nilai_tertinggi);
    printf("nilai rata-rata: %d\n", total_nilai / counter);
}