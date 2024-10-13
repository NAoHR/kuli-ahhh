#include <stdio.h>


void main() {
    int x = 2;
    printf("%d\n",++x + 1);
    printf("%d\n",x++ + x);
    printf("%d\n",++(x) + 1);
    printf("%d\n", ++(x + 1));
}