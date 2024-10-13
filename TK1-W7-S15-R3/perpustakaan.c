#include <stdio.h>

enum MediaType {
    BUKU, MAJALAH
};

struct Buku {
    char isbn[13];
    char penulis[255];
};

struct Majalah {
    char issn[8];
    int edisi;
};


struct Media {
    char judul[255];
    char penerbit[255];
    int tahun_terbit;
    enum MediaType tipe;
    union {
        struct Buku buku;
        struct Majalah majalah;
    } detail;

};


 void display_item(struct Media *media) {
    printf("Judul: %s\n", media->judul);
    printf("Penerbit: %s\n", media->penerbit);
    printf("tahun terbit: %d\n", media->tahun_terbit);
    if(media->tipe == BUKU) {
        printf("Detail Buku\n");
        printf("isbn: %s\n", media->detail.buku.isbn);
        printf("penulis: %s", media->detail.buku.penulis);
    }else if(media->tipe == MAJALAH) {
        printf("Detail Majalah\n");
        printf("issn: %s\n", media->detail.majalah.issn);
        printf("edisi ke-%d\n", media->detail.majalah.edisi);
    }
 }

 void add_item(struct Media *struct_ptr) {
    char type;

    printf("masukkan judul: ");
    scanf("%s", struct_ptr->judul);
    
    printf("Masukkan penerbit: ");
    scanf("%s", struct_ptr->penerbit);

    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &(struct_ptr->tahun_terbit));

    printf("Masukkan Tipe (m/b): ");
    scanf(" %c", &type);

    if(type == 'b') {
        struct_ptr->tipe = BUKU;
        
        printf("Masukkan ISBN: ");
        scanf("%s", struct_ptr->detail.buku.isbn);

        printf("Masukkan Penulis: ");
        scanf("%s", struct_ptr->detail.buku.penulis);

    }else if(type == 'm') {
        struct_ptr->tipe = MAJALAH;

        printf("Masukkan ISSN: ");
        scanf("%s", struct_ptr->detail.majalah.issn);

        printf("Masukkan edisi: ");
        scanf("%d", &(struct_ptr->detail.majalah.edisi));
    }else {

        printf("Tidak dapat menambahkan, tipe tidak valid");
        return;
    }
 }


 void main() {
    int counter;
    printf("masukkan jumlah Item yang ingin ditambahkan: ");
    scanf("%d", &counter);

    struct Media media_list[counter];

    for(int i = 0; i < counter; i++) {
        printf("item ke-%d\n", (i+1));
        add_item(&media_list[i]);
        printf("\n");
    }


    for(int i = 0; i < counter; i++) {
        printf("item ke-%d\n", (i+1));
        display_item(&media_list[i]);
        printf("\n");
    }


 }