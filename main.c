#include "libs.h"
#include "functions.c"


int main(int arg, char *argv[]) {
    int option = 0;
    
    do {
        system("cls");
        printf("\n");
        printf("\n==========================");
        printf("\n========== MENU ==========");
        printf("\n1 --- Cadastrar Cliente");
        printf("\n2 --- Mostrar Clientes");
        printf("\n3 --- Mostrar Cliente pelo id");
        printf("\n4 --- Cadastrar Produto");
        printf("\n5 --- Mostrar Produto");
        printf("\n==========================");
        printf("\n");

        scanf(" %d", &option);

        switch (option)
        {
        case 1:
            insertCustumer();
            break;
        case 2:
            showCustumers();
            break;
        case 3:
            showCustumerById();
            break;
        case 4:
            insertProduct();
            break;
        case 5:
            showProduct();
            break;
    
        default:
            printf("\nOpção Invalida!");
            break;
        }

    } while (option != 0);
};