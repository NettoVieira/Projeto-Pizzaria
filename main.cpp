#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE 0
typedef int bool;


bool doLogin(char user[], char password[]){
    FILE *users;
    bool loginSuccess = FALSE;
    char userFile[25], passwordFile[50];

    users = fopen("users.txt", "r");
    if(users == NULL) {
        printf("Erro ao abrir arquivo !\n");
        exit(0); 
    }
    do {
        if(feof(users)) {
            break;
        }
        fscanf(users, "%s %s", userFile, passwordFile);

        if((strcmp(user, userFile) == 0) && (strcmp(password, passwordFile) == 0)) {
            loginSuccess = TRUE;
            break;
        }

    } while(1);
    
    printf("\n");
    printf("%i \n", loginSuccess);

    fclose(users);
    return loginSuccess;
}

int main(){
    bool login;
    char user[25], password[50];

    printf("Fa�a seu login... \n");
    printf("Usu�rio: ");
    scanf("%s", user);

    printf("Senha: ");
    scanf("%s", password);

    if(doLogin(user, password) == TRUE) {
        printf("VOC� EST� LOGADO \n");
	    
		printf("%s","Selecione a op��o que deseja....\n");
		
		int opcao;	
		
		printf("%s","1) Para cadastrar Cliente....\n", opcao);
		scanf("$i", opcao);
		printf("%s","2) Para Cadastrar Produto....\n", opcao);
		scanf("$i", opcao);
		printf("%s","3) Para acessar os pedidos....\n", opcao);
		scanf("$i", opcao);
		printf("%s","4) Para acessar os pedidos....\n", opcao);
		scanf("$i", opcao);
		printf("%s","5) Para acessar os pedidos....\n", opcao);
		scanf("$i", opcao);
		printf("%s","6) Para acessar os pedidos....\n", opcao);
		scanf("$i", opcao);
    } else {
        printf("SENHA INCORRETA \n");
    }

    return(0);
    System("adsa");
}


