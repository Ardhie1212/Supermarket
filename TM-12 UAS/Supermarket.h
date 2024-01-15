//Dibuat pada tanggal 21 Mei - M Ardhie
#ifndef header_h
#define header_h
#define SIZE 99

typedef struct{
	char username[25];
	char password[25];
}account;

typedef struct{
	int kode;
	char namaproduk[25];
	char kategori[20];
	int harga;
}produk;

int akun = 0;
int produkdftr;
int i;
account accountinput[SIZE];
produk product[SIZE];

void registration();
void login();
void menu();
void tambahproduk();
void updateproduk();
void tampilproduk();
void searchproduk();
void deleteproduk();
void cariproduk();
void carikode(FILE *database);
void carinama(FILE *database);
void seluruh_produk();
void berdasarkan_kode();
void berdasarkan_harga();
void bubblesortharga(int produkdftr);
void bubblesortkode(int produkdftr);

#endif