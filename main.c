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
	
	printf("------------------------------------------\n");
	printf("---------------- PIZZARIA ----------------\n");
	printf("------------------------------------------\n");
	
	do {
		printf("1 - Cliente\n");	
		printf("2 - Pedido\n");	
		printf("3 - Produto\n");	
		printf("4 - Sair \n\n");
		printf("Escolha uma opção: ");
		scanf("%i", &opcao);
		
		switch(opcao){
			case 1:
				system("cls");
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
				system("cls");
			break;
			
			default:
				printf("Opção Invalida \n");
				getch();
				system("cls");
			break;	
		}
		
	} while(opcao != 4);

	system("Pause");
}

void cabecalho(){
	
}

void Cliente(){
	int opcao;
	FILE* arquivo;
	CLIENTE cl;

	do{	
		printf("------------------------------------------\n");
		printf("----------------- CLIENTE ----------------\n");
		printf("------------------------------------------\n");
		
		printf("1 - Deseja Cadastrar\n");
		printf("2 - Deseja Excluir\n");
		printf("3 - Deseja Alterar\n");
		printf("4 - Voltar ao Menu anterior\n\n");
		printf("Escolha uma opção: ");
		scanf("%i", &opcao);
		
		switch(opcao){
			case 1:				
				arquivo = fopen("Cliente.txt", "w");
				
				if(arquivo == NULL){
					printf("Problemas na Abertura do arquivo\n");
				}else{
					do{
						fflush(stdin);		
						printf("Digite o Nome:\n");
						gets(cl.nome);
						
						fflush(stdin);		
						printf("Digite o CPF/CNPJ:\n");
						gets(cl.cpf);
						
						fflush(stdin);		
						printf("Digite o Fone:\n");
						gets(cl.fone);
						
						printf("Digite o Data Nascimento:\n");
						scanf("%d %d %d", &cl.nasc.dia, &cl.nasc.mes, &cl.nasc.ano);
						
						fwrite(&cl, sizeof(CLIENTE), 1, arquivo);
						
						printf("Deseja Cadastrar?(S/N)");
							
					}while(getche() == 's');
					fclose(arquivo);
				}
				getche();
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
				system("cls");
				main();
				getch();
			break;
		}
		
 	} while(opcao != 4);
}


