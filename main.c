#include "libs.h"
#include "functions.c"
#include "structs.h"

int main(int arg, char *argv[])
{

    int option = 0;

    if(isFull(&s)) {
        printf("\nPilha de memoria cheia favor descarregar alguma venda!");
        printf("\n");
        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();
    }

    initialize(&s);

    do
    {
        system("cls");
        printf("\n");
        printf("\n==========================");
        printf("\n========== MENU ==========");
        printf("\n1 --- Cadastrar Cliente");
        printf("\n2 --- Mostrar Clientes");
        printf("\n3 --- Mostrar Cliente pelo id");
        printf("\n4 --- Cadastrar Produto");
        printf("\n5 --- Mostrar Produto");
        printf("\n6 --- Criar Venda (Push)");
        printf("\n7 --- Mostrar Vendas (Mostrar Pilha)");
        printf("\n8 --- Mostrar Ultima Venda da Pilha (Peek)");
        printf("\n9 --- Remover Ultima Venda da Pilha (Pop)");
        printf("\n==========================");
        printf("\n");

        scanf(" %d", &option);

        switch (option)
        {
        case 1:
            insertCustumer();
            break;
        case 2:
            showClient();
            break;
        case 3:
            showClientById();
            break;
        case 4:
            insertProduct();
            break;
        case 5:
            showProduct();
            break;
        case 6:
            inserSale(&s);
            break;
        case 7:
            showSales(&s);
            break;
        case 8:
            showSale(&s);
            break;
        case 9:
            removeSale(&s);
            break;
        default:
            printf("\nOpção Invalida!");
            break;
        }

    } while (option != 0);
};