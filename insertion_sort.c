
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            printf("angka %d berada pada index ke %d\n", target, i);
            break;
        }
        printf("angka tidak ditemukan\n");
    }
}

void displayData(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int counter;
    printf("jumlah angka pada array: ");
    scanf("%d", &counter);

    int arr[counter];
    int *arr_ptr = arr;

    for(int i = 0; i < counter; i++) {
        printf("angka ke-%d: ", i + 1);
        scanf("%d", (arr_ptr + i));
    }

    printf("Data yang belum di sort: ");
    displayData(arr, counter);
    insertionSort(arr, counter);

    printf("Data yang sudah di sort: ");
    displayData(arr, counter);

    int val;
    printf("masukkan value yang ingin di cari: ");
    scanf("%d", &val);
    linearSearch(arr, counter, val);

    return 0;
}