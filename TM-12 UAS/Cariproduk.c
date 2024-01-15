#include <stdio.h>
#include <string.h>
#include "Supermarket.h"

void cariproduk() {
	FILE *database;
	database = fopen("Database.txt", "r");
	int pilihan;

	system("cls");
	printf("Cari Produk Berdasarkan:\n");
	printf("1. Kode Produk\n");
	printf("2. Nama Produk\n");
	printf("Masukkan pilihan: ");
	scanf("%d", &pilihan);

	switch (pilihan) {
		case 1:
			carikode(database);
			break;
		case 2:
			carinama(database);
			break;
		default:
			printf("Pilihan tidak valid.\n");
			break;
	}

	fclose(database);
}

void carikode(FILE *database){
	int kode,found;

	printf("Masukkan Kode Produk: ");
	scanf("%d", &kode);

	produkdftr = 0;
	while (fscanf(database, "%d %s %s %d", &product[produkdftr].kode, product[produkdftr].namaproduk,
				product[produkdftr].kategori, &product[produkdftr].harga) != EOF) {
		if (kode == product[produkdftr].kode) {
			found = 1;
			break;
		}
		produkdftr++;

	}

	if (found == 1) {
		printf("\n------------------------\n");
		printf("Produk ditemukan:\n");
		printf("Kode: %d\n", product[produkdftr].kode);
		printf("Nama Produk: %s\n", product[produkdftr].namaproduk);
		printf("Kategori: %s\n", product[produkdftr].kategori);
		printf("Harga: Rp.%d\n", product[produkdftr].harga);
		printf("------------------------\n");
	} else {
		printf("\nProduk dengan kode %d tidak ditemukan.\n", kode);
	}
}

void carinama(FILE *database) {
	int ketemu = 0;
	char nama[20];

	printf("Masukkan Nama Produk: ");
	scanf("%s", nama);

	produkdftr = 0;
	while (fscanf(database, "%d %s %s %d", &product[produkdftr].kode, product[produkdftr].namaproduk,
				product[produkdftr].kategori, &product[produkdftr].harga) != EOF) {
		if (strcmp(product[produkdftr].namaproduk,nama) == 0){
			ketemu = 1;
			printf("\n------------------------\n");
			printf("Produk ditemukan:\n");
			printf("Kode: %d\n", product[produkdftr].kode);
			printf("Nama Produk: %s\n", product[produkdftr].namaproduk);
			printf("Kategori: %s\n", product[produkdftr].kategori);
			printf("Harga: Rp.%d\n", product[produkdftr].harga);
			printf("------------------------\n");
		}
		produkdftr++;
	}

	if (!ketemu) {
		printf("Produk dengan nama %s tidak ditemukan.\n",nama);
	}
}