//DELETE PRODUK DAN BINARY SEARCH
//SELESAI PADA RABU 24 MEI
#include <stdio.h>
#include "Supermarket.h"

void deleteproduk(){
	FILE *pointer;
	FILE *fptr;
	pointer = fopen("Database.txt","r");
	fptr = fopen("Temp.txt","a+");
	seluruh_produk();
	printf("\nPilih kode produk yang ingin dihapus: ");
	int kode;
	scanf("%d",&kode);

	produkdftr = 0;
	while (fscanf(pointer,"%d %s %s %d",&product[produkdftr].kode,product[produkdftr].namaproduk,
		product[produkdftr].kategori,&product[produkdftr].harga) != EOF) {
		produkdftr++;
	}
	int ketemu = 0;
	int awal = 0;
	int tengah;
	int akhir = produkdftr-1;
	int i;
	bubblesortkode(produkdftr);
	while (awal <= akhir){ //Selama awal tidak melebihi akhir
		tengah = (awal + akhir)/2;
		if (kode == product[tengah].kode){
			ketemu = 1;
			//DISINI BAGIAN DELETE FILE. PENJELASAN OLEH ARDHIE
			for (i = 0; i < produkdftr; i++){
				if (kode != product[i].kode){
					fprintf(fptr,"%d %s %s %d\n",product[i].kode,product[i].namaproduk,
					product[i].kategori,product[i].harga);
				}
			}
			break;
		}
		else if (kode > product[tengah].kode){
			awal = tengah + 1;
		}
		else{
			akhir = tengah - 1;
		}
	}
	fclose(fptr);
	fclose(pointer);
	if (ketemu != 1){
		printf("Masukan kode invalid.\n");
		remove("Temp.txt");
	}
	else{
		printf("Datum berhasil dihapus.\n");
		remove("Database.txt");
		rename("Temp.txt","Database.txt");
	}
	printf("\n");
}