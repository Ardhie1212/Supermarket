//Dibuat pada 21 Mei - M Ardhie
#include <stdio.h>
#include "Supermarket.h"
#include "Registrasi.c"
#include "Login.c"
#include "Tambahproduk.c"
#include "Menu.c"
#include "Updateproduk.c"
#include "Deleteproduk.c"
#include "Cariproduk.c"
#include "Bubblesort.c"
#include "Tampilproduk.c"

int main(){
	system("cls");
	printf("[1]Login\n[2]Buat akun baru\nPilihan anda: ");
	int choice;
	scanf("%d",&choice);
	if (choice == 1){
		login();
	}
	else if (choice == 2){
		registration();
	}
	else {
		main();
	}
	return 0;
}