#include <stdio.h>
#include <stdlib.h>


void tambah(int num1, int num2, int num3) {
    int total = num1 + num2 + num3;
    printf("hasil tambah dari %d + %d + %d = %d\n", num1, num2, num3, total);
}

void kurang(int num1, int num2, int num3) {
    int total = num1 - num2 - num3;
    printf("hasil kurang dari %d - %d - %d = %d\n", num1, num2, num3, total);
}

void kali(int num1, int num2, int num3) {
    int total = num1 * num2 * num3;
    printf("hasil kurang dari %d * %d * %d = %d\n", num1, num2, num3, total);
}

void bagi(int num1, int num2, int num3) {
    if(num1 == 0 || num2 == 0 || num3 == 0) {
        printf("pembagian tidak dapat dijalankan karena ada angka yang 0\n");
        return;
    }

    float total = (float) num1 / (float) num2 / (float) num3;
    printf("hasil pembagian dari %d / %d / %d = %f\n", num1, num2, num3, total);
}

void rata_rata(int num1, int num2, int num3) {
    float avg = ((float) num1 + (float) num2 + (float) num3) / 3;
    printf("rata-rata dari %d %d %d = %f\n", num1, num2, num3, avg);
}

void tanya_angka(int counter, int *num) {
    printf("masukkan angka ke-%d: ", counter);
    scanf("%d", num);
}

void tanya_semua_angka(int *num1, int *num2, int *num3) {
    tanya_angka(1, num1);
    tanya_angka(2, num2);
    tanya_angka(3, num3);
}

void menu() {
    printf("pilih menu\n");
    printf("1. Pertambahan\n");
    printf("2. pengurangan\n");
    printf("3. perkalian\n");
    printf("4. Pembagian\n");
    printf("5. rata-rata\n");
    printf("6. tampilkan semua\n");
    printf("7. Keluar\n");
}

void pilih_menu(int *pilihan) {
    printf("pilih menu: ");
    scanf("%d", pilihan);
}

void selesai(){
    printf("selamat tinggal");
    exit(0);
}


int main() {
    int num1, num2, num3, pilihan;

    menu();
    

    while(1) {
        pilih_menu(&pilihan);
        if(pilihan == 7) {selesai();}

        switch(pilihan) {

            case 1:
                tanya_semua_angka(&num1,&num2,&num3);
                tambah(num1, num2, num3);
                printf("\n");
                break;

            case 2:
                tanya_semua_angka(&num1,&num2,&num3);
                kurang(num1, num2, num3);
                printf("\n");
                break;

            case 3:
                tanya_semua_angka(&num1,&num2,&num3);
                kali(num1, num2, num3);
                printf("\n");
                break;

            case 4:
                tanya_semua_angka(&num1,&num2,&num3);
                bagi(num1, num2, num3);
                printf("\n");
                break;

            case 5:
                tanya_semua_angka(&num1,&num2,&num3);
                rata_rata(num1, num2, num3);
                printf("\n");
                break;

            case 6:
                tanya_semua_angka(&num1,&num2,&num3);
                tambah(num1, num2, num3);
                kurang(num1, num2, num3);
                kali(num1, num2, num3);
                bagi(num1, num2, num3);
                rata_rata(num1, num2, num3);
                printf("\n");
                break;

            case 7:
                selesai();

            default:
                printf("pilihan tidak ada yang cocok");

        }
    }
    


}