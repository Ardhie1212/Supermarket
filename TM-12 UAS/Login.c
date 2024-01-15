//Dibuat pada 21 Mei - M Ardhie
#include <stdio.h>
#include <string.h>
#include "Supermarket.h"

void login(){
	int i;
	int succeed = 0;
    char username[20];
    char password[20];
    FILE *pointer;
    pointer = fopen("accountlist.txt","r");
    
    akun = 0;
    while (fscanf(pointer,"%s %s",accountinput[akun].username,accountinput[akun].password)!=EOF){
    	akun++;
    }
    system("cls");
    printf("///// L O G I N /////\n");
	printf("Username: ");
    scanf ("%s",username);
    printf ("Password: ");
    scanf ("%s",password);
    for (i = 0; i < akun; i++){
    	if (strcmp(accountinput[i].username,username) == 0 && strcmp(accountinput[i].password,password) == 0){
        	printf("Anda berhasil login\n");
        	succeed = 1;
        	menu();
        }
	}
	if (succeed == 0){
		printf("Log in gagal.\n");
		login();
	}
	fclose(pointer);
}