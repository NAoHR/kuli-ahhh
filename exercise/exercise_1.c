#include <stdio.h>

int main() {
    FILE *file;
    int character_count = 0;  // Variabel untuk menghitung karakter
    int c;  // Variabel untuk menyimpan karakter sementara

    // Membuka file haiku.txt dalam mode baca
    file = fopen("haiku.txt", "r");
    
    // Memeriksa apakah file berhasil dibuka
    if (file == NULL) {
        printf("Error: File 'haiku.txt' tidak dapat dibuka.\n");
        return 1;  // Keluar dari program jika file tidak terbuka
    }

    // Membaca isi file dan menghitung jumlah karakternya
    while ((c = fgetc(file)) != EOF) {
        putchar(c);  // Menampilkan isi file di layar
        character_count++;  // Menghitung setiap karakter yang dibaca
    }

    // Menutup file setelah selesai membaca
    fclose(file);

    // Menampilkan jumlah total karakter yang ada di file
    printf("\nTotal number of characters: %d\n", character_count);

    return 0;
}
