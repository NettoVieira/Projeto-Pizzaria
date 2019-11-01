#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
typedef struct data DATA;
struct data {
	int dia;
	int mes;
	int ano;
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct cliente CLIENTE;
struct cliente {
	char nome[30];
	char cpf[11];
	char fone[15];
	DATA nasc;
};

void Cliente();

main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	/*
	(1)Iserir Cliente
	(2)Inserir Pedido
	(3)Inserir Produto
	(4)Sair
	*/
	
	do {
		printf("1 - Cliente\n");	
		printf("2 - Pedido\n");	
		printf("3 - Produto\n");	
		printf("4 - Sair \n ");
		printf("Escolha uma opção: ");
		scanf("%i", &opcao);
		
		switch(opcao){
			case 1:
				Cliente();
				getch();
			break;
			
			case 2:
				//Cadastrar Pedido
			break;
			
			case 3:
				//Cadastrar Produto
			break;
			
			case 4:
				printf("Obrigado por sua visita! \n");
				getch();	
			break;
			
			default:
				printf("Opção Invalida \n");
				getch();
			break;	
		}
		
	} while(opcao != 4);

	system("Pause");
}

void Cliente(){
	int opcao;
	FILE* arquivo;
	CLIENTE cl;
	do{	
		printf("1 - Deseja Cadastrar\n");
		printf("2 - Deseja Excluir\n");
		printf("3 - Deseja Alterar\n");
		printf("4 - Voltar ao Menu anterior\n");
		scanf("%i", &opcao);
		
		switch(opcao){
			case 1:				
				arquivo = fopen("Cliente.txt", "ab");
				
				if(arquivo == NULL){
					printf("Problemas na Abertura do arquivo\n");
				}else{
					do{
						fflush(stdin);		
						printf("Digite o Nome:\n");
						gets(cl.nome);
						
						fflush(stdin);		
						printf("Digite o Nome:\n");
						gets(cl.nome);
						
						fflush(stdin);		
						printf("Digite o Nome:\n");
						gets(cl.nome);
							
					}while(getche() == 's');
					fclose(arquivo);
				}
				getche();
			break;
		}
		
 	} while(opcao != 4);
}


