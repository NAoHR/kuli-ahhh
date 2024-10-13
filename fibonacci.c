#include <stdio.h>

int main() {
    unsigned int first =0, second = 1;
    unsigned int temp = 0;
    int input;

    printf("Masukkan jumlah deret fibonacci yang ingin anda lihat: ");
    scanf("%d", &input);

    if(input <= 0) {
        printf("angka hanya bisa dimulai dari 1");
        return -1;
    }

    for(int i = 1; i <= input; i++) {
        for(int j =1; j <= i; j++) {
            if(j == 1) {
                printf("%u", first);
            }else if(j == 2) {
                printf("%u", second);
            } else {
                temp = first;
                first = second;
                second = temp + first;
                printf("%u", second);
            }

            printf(" ");
        }

        first = 0;
        second = 1;
        temp = 0;
        printf("\n");
    }

    return 0;

}