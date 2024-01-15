//Dibuat pada 21 Mei - M Ardhie
#include <stdio.h>
#include <string.h>

void registration(){
	FILE *pointer;
	pointer = fopen("accountlist.txt","a+"); //pointer membuka accountlist
	
	akun = 0;
	while (fscanf(pointer,"%s %s",accountinput[akun].username,accountinput[akun].password) != EOF){
		akun++; 
		//Mendeteksi setiap akun yang sudah terdapat pada accountlist
	}
	system("cls");
	printf("///// Registrasi /////\n");
	printf("Silahkan buat username baru.");
	printf("\nUsername: ");
	scanf("%s",accountinput[akun].username);
	printf("\nSilahkan membuat password.\n");
	printf("Password: ");
	scanf("%s",accountinput[akun].password);
	printf("\nPembuatan akun baru berhasil. \n");
	fprintf(pointer,"%s %s\n",accountinput[akun].username, accountinput[akun].password);
	//fprintf akan menyimpan akun baru ke dalam accountlist. 
	akun++;
	fclose(pointer);
	login();
}