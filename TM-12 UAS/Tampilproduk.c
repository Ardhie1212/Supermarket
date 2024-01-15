#include <stdio.h>
#include "Supermarket.h"
#include <string.h>
#include <stdlib.h>

void tampilproduk(){
    int pilih;
    system("cls");
    printf("[1]Tampilkan seluruh produk\n");
    printf("[2]Tampilkan Berdasarkan Harga Terendah\n");
    printf("[3]Tampilkan Berdasarkan Kode Terkecil\n");
    printf("Pilih salah satu: ");
    scanf("%d", &pilih);

    switch (pilih){
        case 1:
            seluruh_produk();
            break;
        case 2:
            berdasarkan_harga();
            break;
        case 3:
            berdasarkan_kode();
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
}

void seluruh_produk(){
    system("cls");
    FILE *database;
    database = fopen("Database.txt", "r");
    int n;
    produkdftr = 0;
    printf("================== Data Produk ==================\n");
    printf("---------------------------------------------\n");
    printf("Kode\tProduk\t\tKategori\tHarga\n");
    printf("---------------------------------------------\n");
    while(fscanf(database,"%d %s %s %d",&product[produkdftr].kode,
        product[produkdftr].namaproduk, product[produkdftr].kategori,&product[produkdftr].harga) != EOF){
        printf("%d\t", product[produkdftr].kode);
        printf("%s\t\t", product[produkdftr].namaproduk);
        printf("%s\t", product[produkdftr].kategori);
        printf("%d\n", product[produkdftr].harga);
        produkdftr++;
    }
    printf("---------------------------------------------\n");
    fclose(database);
}


void berdasarkan_kode(){
    system("cls");
    FILE *database;
    database = fopen("Database.txt", "r");
    produkdftr = 0;
    while(fscanf(database,"%d %s %s %d",&product[produkdftr].kode,
        product[produkdftr].namaproduk, product[produkdftr].kategori,&product[produkdftr].harga) != EOF){
        produkdftr++; //Menghitung panjang array
    }
    bubblesortkode(produkdftr);
    printf("============== Data Produk ==================\n\n");
    printf("---------------------------------------------\n");
    printf("Kode\tProduk\t\tKategori\tHarga\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < produkdftr; i++){
        printf("%d\t", product[i].kode);
        printf("%s\t\t", product[i].namaproduk);
        printf("%s\t", product[i].kategori);
        printf("%d\n", product[i].harga);
    }
    printf("---------------------------------------------\n");
    fclose(database);
}
void berdasarkan_harga(){
    system("cls");
    int harga;
    FILE *database;
    database = fopen("Database.txt","r");
    int i;
    produkdftr = 0;
    while(fscanf(database,"%d %s %s %d",&product[produkdftr].kode,
        product[produkdftr].namaproduk, product[produkdftr].kategori,&product[produkdftr].harga) != EOF){
        produkdftr++; //Menghitung panjang array
    }
    bubblesortharga(produkdftr);
    printf("============== Data Produk ==================\n\n");
    printf("---------------------------------------------\n");
    printf("Kode\tProduk\t\tKategori\tHarga\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < produkdftr; i++){
        printf("%d\t", product[i].kode);
        printf("%s\t\t", product[i].namaproduk);
        printf("%s\t", product[i].kategori);
        printf("%d\n", product[i].harga);
    }
    printf("---------------------------------------------\n");
    fclose(database);
}