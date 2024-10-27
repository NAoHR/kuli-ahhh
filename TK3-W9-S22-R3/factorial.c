#include <stdio.h>


int factorial(int n) {
    printf("%d\n", n);
    if(n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

void main() {

    printf("Nilai Factorial dari 5 adalah %d\n", factorial(5));

}