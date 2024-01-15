//OLEH SHAFIRA 1 JUNI
#include <stdio.h>
#include <string.h>
#include "Supermarket.h"

void bubblesortharga(int produkdftr){
    int i,j;
    produk temp;

    for (i = 0; i < produkdftr-1; i++) {
        for (j = 0; j < produkdftr-1; j++) {
            if (product[j].harga > product[j+1].harga) {
                temp = product[j];
                product[j] = product[j+1];
                product[j+1] = temp;
            }
        }
    }
}

void bubblesortkode(int produkdftr){
    int i, j;
    produk temp;
    for (i = 0; i < produkdftr-1; i++) {
        for (j = 0; j < produkdftr-1; j++) {
            if (product[j].kode > product[j+1].kode) {
                temp = product[j];
                product[j] = product[j+1];
                product[j+1] = temp;
            }
        }
    }
}


