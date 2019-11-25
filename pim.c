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

    fclose(users);
    return loginSuccess;
}

// void recipe(){
//     // id pizza: [id produto, quantitidade produto ......]
//     FILE *items, *recipes;
//     int option=1, contador=1, ingredientId;
//     char temp, ch, receita[300], buffer[30];
//     float quantity;

//     do{
//         printf("DESEJA ADICIONAR UM INGREDIENTE ? COLOQUE O ID \n");
//         scanf("%i", &ingredientId);
//         printf("ADICIONE A QUANTIDADE \n");
//         scanf("%f", &quantity);
        
//         sprintf(buffer, "%i - %f", ingredientId, quantity);
//         strcat(receita, buffer);

//         printf("DESEJA ADICIONAR MAIS UM INGREDIENTE ? 1 = SIM, 0 = NÃO \n");
//         scanf("%i", &option);
//         if(option != 0){
//             strcat(receita, ", ");
//         }
//     } while(option != 0);

//     items = fopen("recipe.txt", "r+");
//     while(!feof(items)){
//         ch = fgetc(items);
//         if(ch == '\n') {
//             contador++;
//         }
//     }
//     fclose(items);
//     recipes = fopen("recipe.txt", "a+");

//     fprintf(recipes, "%i: %s \n", contador, receita);
//     fclose(recipes);
// }

void registerPizza(){
    FILE *items, *pizzas;
    int contador=1;
    char temp, ch, pizza[100];
    float value;

    printf("Cadastre sua pizza: ");
    scanf("%c",&temp); // temp statement to clear buffer
	fgets(pizza, 100, stdin);

    printf("\nCadastre o valor: ");
    scanf("%f", &value);
   
    items = fopen("pizzas.txt", "r+");
    while(!feof(items)){
        ch = fgetc(items);
        if(ch == '\n') {
            contador++;
        }
    }
    fclose(items);
    pizzas = fopen("pizzas.txt", "a+");

    fprintf(pizzas, "%i: %.2f - %s", contador, value, pizza); //escrever com ponto e não virgula -> 19.99
    fclose(pizzas);
}

// void registerNewStock(){//
//     FILE *items, *stocksFile;
//     int contador=1;
//     char temp, ch, stockItem[100];
//     float quantity;

//     printf("Cadastre seu item no estoque: ");
//     scanf("%c",&temp); // temp statement to clear buffer
// 	fgets(stockItem, 100, stdin);
//     printf("Cadastre a quantidade do item \n");
//     scanf("%f", &quantity);

//     items = fopen("estoque.txt", "r+");
//     while(!feof(items)){
//         ch = fgetc(items);
//         if(ch == '\n') {
//             contador++;
//         }
//     }
//     fclose(items);
//     stocksFile = fopen("estoque.txt", "a");

//     fprintf(stocksFile, "%i: %f - %s", contador, quantity, stockItem);
//     fclose(stocksFile);

// }

// void updateStock(){//
//     FILE *stocksFile;
//     int contador = 1, lineNumber = 4; //passar valor da linha como parâmetro da pizza a ser escolhida
//     char ch, testtttt[100], line[100];

//     int test;
//     char test2[100];
//     float test3;

//     stocksFile = fopen("estoque.txt", "r+");
//     while (fgets(line, sizeof line, stocksFile) != NULL) {
//         if (contador == lineNumber) {
//             printf("entrou\n");
//             printf("%s", line);
//             contador++;
//             // sscanf(line, "%i: %f - %[^]0-9]", &test, &test3, test2);

//             break;
//         }
//         else {
//             // fputs(line, stocksFile); //problema, imprime apenas a primeira e sai do arquivo
//             printf("IMPRIMINDO LINHA : %s", line);
//             contador++;
//         }
//     }
//     sscanf(line, "%i: %f - %[^]0-9]", &test, &test3, test2);

//     printf("AGORA VAI \n");
//     printf("\nID: %i", test);
//     printf("\nFLOAT: %f", test3);
//     printf("\nNOME: %s \n", test2);

//     //fazer as contas e débitos, e escrever novamente no arquivo

//     fclose(stocksFile);

// }

// void registerStock(){//
//     FILE *stock;
//     char newItem[1];
//     //ver se é item novo ou não
//     printf("Irá adicionar um item novo ? S = sim, N = não \n");
//     scanf("%s", newItem);
//     printf("\n");

//     if(strcmp(newItem, "s") == 0 || strcmp(newItem, "S") == 0){
//         printf("========== É UM NOVO ITEM\n");
//         //fazer adição de item, igual adição de pizza
//         registerNewStock();
//     }
//     else {
//         //achar a linha que está sendo alterada
//         printf("erro");
//     }

// }

void order() {
    FILE *pizzas;
    float value, finalValue;
    int sizeOfId, idPizza, idPedido = 4, qtde = 1; // id e qtde do pedido irá vir do socket, 3 para testar
    int idFilePizza;
    char *line = NULL, dest[5], namePizza[100];
    size_t len;
    ssize_t read;

    //limpa array dest p/ nao pegar lixo
    for(int i = 0; i<= sizeof dest; i++){
        dest[i] = '\0';
    }

    pizzas = fopen("pizzas.txt", "r+");

    while ((read = getline(&line, &len, pizzas)) != -1) {
        sizeOfId = strcspn(line, ":"); // pega o numero de caracteres até o :
        strncpy(dest, line, sizeOfId); // copia os primeiros n numeros para o array dest
        idPizza = atoi(dest);
        
        if(idPizza == idPedido){
            printf("%s", line);
            sscanf(line, "%i: %f - %s",  &idPizza, &value, namePizza);
            break;
        }
    }

    //escrever final value no arquivo de pedidos
    finalValue = qtde * value;

    printf("\n\nVALOR FINAL : %.2f\n", finalValue);

    fclose(pizzas);
    free(line);
}

int main(){
    bool login;
    int menu;
    char user[25], password[50];

    // fazer menu aqui
    printf("Faça seu login... \n");
    printf("Usuário: ");
    scanf("%s", user);

    printf("Senha: ");
    scanf("%s", password);

    if(doLogin(user, password) == TRUE) {
        printf("DIGITE 1 PARA CADASTRAR UMA PIZZA, 2 PARA ALTERAR O ESTOQUE, 3 PARA ADD RECEITA \n");
        scanf("%i", &menu);
        switch (menu)
        {
        case 1:
            registerPizza();
            break;
        case 2:
            // registerStock();
            break;
        case 3:
            // recipe();
            break;
        case 4:
            order();
            break;
        default:
            break;
        }

    } else {
        printf("SENHA INCORRETA \n");
    }



    return(0);
}