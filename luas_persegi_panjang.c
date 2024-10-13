#include <stdio.h>

int hitungLuasPersegiPanjang(int panjang, int lebar);

void main() {
    // deklarasi variable
    int panjang, lebar, luas;

    // input user
    printf("Selamat datang di program penghitung persegi panjang\n");
    
    printf("Masukkan Panjang: ");
    scanf("%d", &panjang);

    printf("Masukkan Lebar: ");
    scanf("%d", &lebar);

    // proses hitung
    luas = hitungLuasPersegiPanjang(panjang, lebar);

    printf("Hasil dari Persegi panjang dengan panjang %d dan lebar %d adalah: %d\n", panjang, lebar, luas);
}

int hitungLuasPersegiPanjang(int panjang, int lebar) {
    return panjang * lebar;
}