#include <stdio.h>

struct Product {
    char nama[255];
    int harga;
    int stock;
};

int main() {
    int counter = 0;

    printf("masukkan sebanyak: ");
    scanf("%d", &counter);

    struct Product products[counter];

    for(int i = 0; i < counter; i++) {
        printf("masukkan product ke %d\n", i + 1);
        printf("Masukkan nama product: ");
        scanf("%s", products[i].nama);

        printf("Masukkan harga product: ");
        scanf("%d", &(products[i].harga));

        printf("Masukkan stock product: ");
        scanf("%d", &(products[i].stock));
        printf("\n");

    }

    for(int i = 0; i < counter; i++) {
        printf("==========================\n");
        printf("product ke-%d\n", i + 1);
        printf("nama product: %s\n", products[i].nama);
        printf("harga product: %d\n", products[i].harga);
        printf("stock product: %d\n", products[i].stock);
        printf("==========================\n");
    }
    
}