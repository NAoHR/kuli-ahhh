#include <stdio.h>
#include <stdlib.h>

float average(int *array_ptr, int jumlah) {
    // logic untuk kalkulasi average nilai
    int total = 0;
    for(int i = 0; i < jumlah; i++) {
        total += * (array_ptr + i);
    }

    return ((float) total / (float) jumlah);
}

void input_nilai(int counter, int *array_ptr) {
    // pada bagian ini terdapat logic untuk melakukan input pada nilai untuk satu satu item pada array
    int nilai;
    do
    {
        printf("[INFO] input nilai mahasiswa ke %d: ", counter + 1);
        scanf("%d", &nilai);

        if(nilai < 0) {
            printf("[ERROR] nilai tidak boleh minus\n");
        }else if(nilai > 100) {
            printf("[ERROR] nilai tidak boleh lebih dari 100\n");
        }
    } while (nilai < 0 || nilai > 100);
    

    * (array_ptr + counter) = nilai;
}

void proses_nilai(int jumlah_siswa, int * array_ptr, int *min_score, int *max_score) {
    /*
     * pada bagian ini terdapat looping untuk tiap jumlah mahasiswa, 
     * terdapat algoritma pengecekan untuk skor terendah dan tertinggi 
     * tanpa adanya sorting
    */
    for(int i = 0; i < jumlah_siswa; i++) {
        input_nilai(i, array_ptr);

        if(i == 0) {
            *min_score = *(array_ptr + i);
            *max_score = *(array_ptr + i);
        } else {
            if(*(array_ptr + i) < *min_score) {
                *min_score = *(array_ptr + i);
            }
            if(*(array_ptr + i) > *max_score) {
                *max_score = *(array_ptr + i);
            }
        }
    }

}


void pilih_menu(int *pilihan_ptr) {
    printf("[INFO] pilih menu: ");
    scanf("%d", pilihan_ptr);
}

void menu() {
    printf("pilih menu\n");
    printf("1. skor minimum\n");
    printf("2. skor maximum\n");
    printf("3. skor rata-rata\n");
    printf("4. keluar\n");
}

int main() {
    int jumlah_siswa = 5;
    int min_score = 0;
    int max_score = 0;
    int data_nilai[jumlah_siswa];
    int pilihan_menu;

    printf("[INFO] silahkan masukan nilai mahasiswa\n");
    proses_nilai(jumlah_siswa, data_nilai, &min_score, &max_score);
    menu();

    while(1) {
        pilih_menu(&pilihan_menu);

        switch(pilihan_menu) {
            case 1:
                printf("[INFO] minimum score: %d\n", min_score);
                break;
            case 2:
                printf("[INFO] maximum score: %d\n", max_score);
                break;
            case 3:
                printf("average : %f\n", average(data_nilai, jumlah_siswa));
                break;
            case 4:
                exit(0);
            default:
                printf("[INFO] hanya bisa memilih 1 sampai 4\n");
        }
    }

    return 0;    
}