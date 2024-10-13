#include <stdio.h>

void main() {
    int ch;
    
    ch = 65;

    printf("The caracter that has numeric value of 65 is:\n");
    putc(ch, stdout); // takes int (ascii number) and stream it to the out put. current cases is the stdout (keyboard)
    
    return;
}

/*  OUTPUT
    The caracter that has numeric value of 65 is:
    A
*/