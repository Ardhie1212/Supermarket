//PROGRAM MENU OLEH HIKMAL. SELESAI PADA SENIN 22 MEI
#include <stdio.h>
#include <stdlib.h>
#include "Supermarket.h"

void menu() {
    int choice;

    do {
        system("cls");
        printf("Selamat datang di aplikasi.\n");
        printf("Silahkan pilih salah satu.\n");
        printf("[1] Tambah Produk Baru\n");
        printf("[2] Lihat Semua Produk\n");
        printf("[3] Perbarui Data Produk\n");
        printf("[4] Hapus Data Produk\n");
        printf("[5] Cari Produk\n");
        printf("[6] Log Out\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tambahproduk();
                break;
            case 2:
                tampilproduk();
                break;
            case 3:
                updateproduk();
                break;
            case 4:
                deleteproduk();
                break;
            case 5:
                 cariproduk();
                break;
            case 6:
            	system("cls");
            	printf("\nAnda Log Out");
            	exit(0);
            default:
                printf("Pilihan salah\n");
                break;
        }
        printf("Tekan enter untuk melanjutkan...");
        getchar();
        getchar();  // Menunggu input dari sebelum lanjut ke menu
    } while (choice != 6);
}
