#include <stdio.h>


void testing(int *array) {
    for(int i = 0; i < 5; i++) {
        printf("%d", *(array + i));
    }
}

void main() {
    int nilai[5];

    nilai[0] = 1;
    nilai[1] = 2;
    nilai[2] = 3;
    nilai[3] = 4;
    nilai[4] = 5;

    testing(nilai);


}