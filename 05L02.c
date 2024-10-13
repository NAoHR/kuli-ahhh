#include <stdio.h>

void main() {
    int ch1, ch2;

    printf("Please type in two characters together:\n");
    ch1 = getc(stdin); // accept * FILE
    ch2 = getchar(); // accept void

    printf("The first character you just entered is: %c\n", ch1);
    printf("The second character you just entered is: %c\n", ch2);

}

/*  OUTPUT: 

    Please type in two characters together:
    as
    The first character you just entered is: a
    The second character you just entered is: s
*/