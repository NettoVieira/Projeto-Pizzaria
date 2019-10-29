#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct data DATA;
struct data {
	int dia;
	int mes;
	int ano;
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct cliente CLIENTE;
struct contato {
	char nome[30];
	char cpf[11]
	char fone[15];
	DATA nasc;
};

main(){
	int opcao;
	/*
	(1)Iserir Cliente
	(2)Inserir Pedido
	(3)Inserir Produto
	(4)Sair
	*/
	
	do {
		printf("(1)Cadastrar Cliente/n ");	
		printf("(2)Cadastrar Pedido/n  ");	
		printf("(3)Cadastrar Produto/n ");	
		printf("(4)Sair/n ");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				//Cdastrar Cliente
			break;
			
			case 2:
				//Cadastrar Pedido
			break;
			
			case 3:
				//Cadastrar Produto
			break;
			
			case 4:
				printf("Obrigado por sua visita!");
				getch();	
			break;
			
			default:
				printf("Opcao Invalida");
				getch();
			break;	
		}
		
	} while(opcao != 4);

}
