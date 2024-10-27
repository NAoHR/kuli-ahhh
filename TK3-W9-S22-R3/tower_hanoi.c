#include <stdio.h>


void tower_of_hanoi(int n, char * t1, char *t2, char *t3) {
    if(n == 1) {
        printf("Pindahkan disk %d dari %s ke %s\n", n, t1, t3);
        return;
    }

    tower_of_hanoi(n-1, t1, t3, t2);
    printf("Pindahkan disk %d dari %s ke %s\n", n, t1, t3);
    tower_of_hanoi(n-1, t2, t1, t3);
}


void main() {
    int disc;

    printf("Masukkan Jumlah Disc: ");
    scanf("%d", &disc);

    tower_of_hanoi(disc, "T1", "T2", "T3");

}