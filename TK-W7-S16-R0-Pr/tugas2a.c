#include <stdio.h>
#define DISCOUNT_PERCENTAGE 5
#define PRICE_MULTIPLE 100000

struct Order {
    char nama_barang[255];
    float harga;
};

struct Result {
    int discount;
    float discount_price;
    float total_price;
};

void input_items_and_price(struct Order *order_ptr) {
    printf("Masukkan nama barang: ");
    scanf("%s", order_ptr->nama_barang);

    printf("Masukkan Harga barang: ");
    scanf("%f", &order_ptr->harga);

    printf("\n");
}


struct Result calculate_final_discount(struct Order *order_ptr, int *counter_ptr) {
    // proses kalkulasi perhitungan tiket diskon, nominal diskon, dan hasil akhir
    struct Result result;
    int total_ticket;
    float discount_total;
    int i = 0;
    float total = 0;

    while(i < *counter_ptr) {
        total += order_ptr->harga;
        order_ptr +=1;
        i++;
    }

    total_ticket = total / PRICE_MULTIPLE;
    discount_total = total_ticket * DISCOUNT_PERCENTAGE;
    
    result.discount = discount_total;
    result.total_price = total;
    result.discount_price = total * discount_total / 100;

    return result;
    
}

void display_result(struct Result result){
    printf("==== TOTAL ====\n");
    printf("total: %2.f\n", result.total_price);
    printf("discount percentage: %d%%\n", result.discount);
    printf("discount price: %.2f\n", result.discount_price);
    printf("after discount: %.2f\n", result.total_price - result.discount_price);
}


void main() {
    int i = 0;
    int counter;
    struct Result result;

    printf("Masukkan Banyak Barang: ");
    scanf("%d", &counter);

    struct Order order_list[counter];

    while(i < counter) {
        input_items_and_price(&order_list[i]);
        i++;
    }


    result = calculate_final_discount(order_list, &counter);
    display_result(result);
    
}