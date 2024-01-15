//Dibuat 21 Mei
#include <stdio.h>
#include "Supermarket.h"

void tambahproduk(){
	FILE *tambah;
	tambah = fopen("Database.txt","a+");
	int kode;
	int unique = 0;

	system("cls");
	produkdftr = 0;
	while(fscanf(tambah,"%d %s %s %d",&product[produkdftr].kode,
		product[produkdftr].namaproduk,	product[produkdftr].kategori,&product[produkdftr].harga) != EOF) {
		produkdftr++;
	}
	while (unique == 0){
		printf("Masukkan Kode Produk yang baru: ");
		scanf("%d",&kode);
		unique = 1;
		for (i = 0; i < produkdftr; i++){
			if (kode == product[i].kode){
				printf("\nKode sudah digunakan.\n");
				unique = 0;
				break;
			}
		}
	}
	product[produkdftr].kode = kode;
	printf("\nMasukkan Nama Produk: ");
	scanf("%s",product[produkdftr].namaproduk);
	printf("\nMasukkan Kategori Produk: ");
	scanf("%s",product[produkdftr].kategori);
	printf("\nMasukkan harga produk: Rp.");
	scanf("%d",&product[produkdftr].harga);
	fprintf(tambah,"%d %s %s %d\n",product[produkdftr].kode,product[produkdftr].namaproduk,
		product[produkdftr].kategori,product[produkdftr].harga);
	fclose(tambah);
	produkdftr++;
}