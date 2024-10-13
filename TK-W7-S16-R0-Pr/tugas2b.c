#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define GOLONGAN_LENGTH 3
#define MINIMUM_CAPACITY 5

struct Golongan {
    char tipe[3];
    float gaji;
    float lembur;
};

struct Pegawai {
    char nip[13];
    char nama[100];
    char alamat[255];
    char no_hp[13];
    char jabatan[13];
    struct Golongan *golongan;
};


struct Golongan* find_golongan(char * input, struct Golongan * golongan) {
    // fungsi untuk mencari golongan dari hasil inputan
    for(int i = 0; i < GOLONGAN_LENGTH; i++) {
        if(strcasecmp(input, golongan[i].tipe) == 0) {
            return &golongan[i];
        }
    }

    return NULL;
}

struct Pegawai* find_pegawai(struct Pegawai * pegawai, int size, char * nip, char * golongan) {
    // fungsi untuk mencari golongan dari hasil inputan. dilakukan komparasi nip dan golongan
    for(int i = 0; i < size; i++) {
        if(pegawai[i].nip == NULL) continue;
        if(strcasecmp(pegawai[i].nip, nip) == 0 && strcasecmp(pegawai[i].golongan->tipe, golongan) == 0) {
            return &pegawai[i];
        }
    }
    return NULL;
}

void display_pegawai(struct Pegawai * pegawai) {
    printf("Data Pegawai\n");
    printf("NIP: %s\n", pegawai->nip);
    printf("Nama: %s\n", pegawai->nama);
    printf("Alamat: %s\n", pegawai->alamat);
    printf("No HP: %s\n", pegawai->no_hp);
    printf("Jabatan: %s\n", pegawai->jabatan);
    printf("Golongan: %s\n", pegawai->golongan->tipe);
    printf("Gaji: %.2f\n", pegawai->golongan->gaji);
}

void display_menu() {
    printf("1. Tambahkan pegawai\n");
    printf("2. Kalkulasi Gaji Lembur Pegawai\n");
    printf("3. Keluar\n");
}

void calculate_gaji(struct Pegawai * pegawai, int lembur) {
    // fungsi untuk kalkulasi gaji dan lembur
    float total_lembur = lembur * pegawai->golongan->lembur;
    float total_gaji = pegawai->golongan->gaji + total_lembur;
    
    printf("gaji: %.2f\n", pegawai->golongan->gaji);
    printf("total lembur: %.2f\n", total_lembur);
    printf("total gaji: %.2f\n", total_gaji);

    printf("Gaji bulan ini: %.2f\n", total_gaji);
}


struct Pegawai input_pegawai(struct Golongan * golongan) {
    // fungsi untuk membuat data pegawai
    struct Golongan *fg = NULL;
    struct Pegawai p;
    char * gol;

    printf("Nip: ");
    scanf("%s", p.nip);

    printf("Nama: ");
    scanf("%s", p.nama);

    printf("Alamat: ");
    scanf("%s", p.alamat);

    printf("No Hp: ");
    scanf("%s", p.no_hp);

    printf("jabatan: ");
    scanf("%s", p.jabatan);

    while(fg == NULL) {
        printf("Golongan (D1, D2, D3): ");
        scanf("%s", gol);
        fg = find_golongan(gol, golongan);
        if(fg == NULL) {
            printf("Golongan tidak ditemukan, input ulang\n");
        }
        p.golongan = fg;
    }

    return p;
}

void input_lembur(struct Pegawai * pegawai, int size) {
    struct Pegawai *pg = NULL;
    char nip[13];
    char golongan[3];
    int lembur;
    
    do{
        printf("Nip: ");
        scanf("%s", nip);
        printf("Golongan: ");
        scanf("%s", golongan);

        pg = find_pegawai(pegawai, size, nip, golongan);
        if(pg != NULL) {
            printf("Lembur: ");
            scanf("%d", &lembur);

        }else {
            printf("pegawai tidak ditemukan\n");
        }
    } while(pg == NULL);

    calculate_gaji(pg, lembur);



}

int main() {
    int pegawai_counter = 0;
    int maxium_pegawai = MINIMUM_CAPACITY;
    int menu;

    struct Golongan golongan_list[] = {
        { "D1", 2500000, 10000 },
        { "D2", 2000000, 5000 },
        { "D3", 1500000, 2500 }
    };
    struct Pegawai *pegawai_list;

    pegawai_list = (struct Pegawai*)malloc(MINIMUM_CAPACITY * sizeof(struct Pegawai)); // deklarasi dynamic array dengan size awal sesuai dengan minimum capacity

    display_menu();

    while(1) {
        printf("Pilih Menu: ");
        scanf("%d", &menu);

        if(menu == 1) {
            if(pegawai_counter == maxium_pegawai) {
                // resize array apabila sudah penuh, kita akan mengalokasikan 5 tempat yang baru
                pegawai_list = (struct Pegawai*)realloc(pegawai_list, sizeof(struct Pegawai) * (pegawai_counter + 5));
                maxium_pegawai += 5;
            }
            pegawai_list[pegawai_counter] = input_pegawai(golongan_list);
            display_pegawai(&pegawai_list[pegawai_counter]);
            pegawai_counter++;
            printf("\n");

        }else if(menu == 2) {
            input_lembur(pegawai_list, maxium_pegawai);
            printf("\n");

        } else if(menu == 3) {
            printf("Selamat Tinggal");
            return 0;

        } else {
            printf("Pilihan Menu tidak Valid");
        }

    }
    
}