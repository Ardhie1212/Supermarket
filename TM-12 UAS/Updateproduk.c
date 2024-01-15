#include "Supermarket.h"
#include <stdio.h>

void updateproduk(){
    int pilih;
    FILE *pointer;
    FILE *fptr;

    pointer = fopen ("Database.txt", "r");
    fptr = fopen("Temp.txt","a+");

    system("cls");
    
    int choice;
    produkdftr = 0;
    int ketemu = 0;
    while (fscanf(pointer,"%d %s %s %d\n",&product[produkdftr].kode,product[produkdftr].namaproduk,
        product[produkdftr].kategori,&product[produkdftr].harga) != EOF){
        produkdftr++; //Menghitung banyak data di dalam database.txt
    }//endwhile

    //deklarasi
    int tengah;
    int awal = 0;
    int akhir = produkdftr-1;
    int cari;
    seluruh_produk();
    printf("\nPilih Kode Produk yang ingin diubah: ");
    scanf("%d",&cari);
    bubblesortkode(produkdftr); //Binary search harus sorting dulu
    
    while (awal <= akhir){ //Selama nilai awal tidak melebihi akhir
        tengah = (awal + akhir)/2;
        if (cari == product[tengah].kode){ //Input user ketemu
            ketemu = 1; //Inisialisasi untuk output.
            //EDIT PRODUK (ARDHIE) SELESAI PADA 24 MEI
            for (i = 0; i < produkdftr; i++){
                if (cari == product[i].kode){
                    printf("[1]Nama: %s\n", product[i].namaproduk);
                    printf("[2]Kategori: %s\n", product[i].kategori);
                    printf("[3]Harga: %d\n", product[i].harga);
                    printf("Data yang ingin diubah? "); //EDIT 
                    scanf("%d",&choice);
                    if (choice == 1){
                        char new_name[25];
                        printf("\nNama baru: ");
                        scanf("%s",new_name);
                        fprintf(fptr,"%d %s %s %d\n",product[i].kode,new_name,product[i].kategori,
                        product[i].harga);
                    }
                    else if (choice == 2){
                        char new_kategori[20];
                        printf("\nKategori Baru: ");
                        scanf("%s",new_kategori);
                        fprintf(fptr,"%d %s %s %d\n",product[i].kode,product[i].namaproduk,
                            new_kategori,product[i].harga);
                    }
                    else {
                        printf("\nHarga baru: ");
                        int new_harga;
                        scanf("%d",&new_harga);
                        fprintf(fptr,"%d %s %s %d\n",product[i].kode,product[i].namaproduk,
                            product[i].kategori,new_harga);
                    }
                }
                else {
                    fprintf(fptr,"%d %s %s %d\n",product[i].kode,product[i].namaproduk,
                        product[i].kategori,product[i].harga);
                }
            }
            break;
        }
        //BINARY SEARCH - NANDA
        else if (cari > product[produkdftr].kode){
            awal = tengah + 1; //Awal akan bertambah terus jika input > tengah.
        }
        //BINARY SEARCH - NANDA
        else{
            akhir = tengah - 1; //Akhir akan berkurang terus jika input < tengah
        }
    }
    if (ketemu != 1){
        fclose(pointer);
        fclose(fptr);
        printf("Masukan kode invalid.\n");
        remove("Temp.txt");
    } 
    else{
        fclose(pointer);
        fclose(fptr);
        remove("Database.txt");
        rename("Temp.txt", "Database.txt");
        printf("Datum berhasil diubah.\n");
    }
}