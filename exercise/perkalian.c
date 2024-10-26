#include <stdio.h>

int kali(int a, int b) {
    return a * b;
}

int main() {
    int num1, num2, hasil;

    printf("Masukkan bilangan pertama: ");
    scanf("%d", &num1);

    printf("Masukkan bilangan kedua: ");
    scanf("%d", &num2);

    hasil = kali(num1, num2);

    printf("Hasil perkalian: %d\n", hasil);

    return 0;
}