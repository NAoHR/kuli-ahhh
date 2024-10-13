#include <stdio.h>

void fun(int *p[][4]){}
int main() {
   int a[10] = {2, 1, 4, 22, 21, 11, 13, 7, 16, 23};

    int i, j, m;

    i = ++a[1];

    j= a[1]++;

    m = a[i++];

    printf("%d, %d, %d", i, j, m);

    return 0;
}