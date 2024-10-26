#ifndef FUNCTIONS_C
#define FUNCTIONS_C

#include "structs.h"
#include "constants.h"
#include "libs.h"

struct Client clients[MAX_LENGHT];
int clientsLength = -1;

struct Product products[MAX_LENGHT];
int productsLength = -1;

void insertCustumer()
{
    system("cls");

    clientsLength++;

    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", clients[clientsLength].name);

    clients[clientsLength].code = clientsLength;

    printf("\nCliente cadastrado com sucesso!");
    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void insertProduct()
{
    system("cls");

    productsLength++;

    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]", products[productsLength].name);

    printf("\nDigite a descricao do produto: ");
    scanf(" %[^\n]", products[productsLength].description);

    printf("\nDigite a quantidade em estoque do produto: ");
    scanf("%d", &products[productsLength].quantity);

    printf("\nDigite o preco do produto: ");
    scanf("%f", &products[productsLength].price);

    products[productsLength].code = productsLength;

    printf("\nProduto cadastrado com sucesso!");
    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void printClient(int index)
{
    printf("\n");
    printf("\n==========================");
    printf("\nid: %d", clients[index].code);
    printf("\nNome: %s", clients[index].name);
    printf("\n==========================");
    printf("\n");
}

void showClient()
{
    system("cls");

    for (int i = 0; i <= clientsLength; i++)
    {
        printClient(i);
    }

    if (clientsLength < 0)
    {
        printf("\nSem clientes cadastrados!");
    }

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void printProduct(int index) {

    printf("\n");
    printf("\n==========================");
    printf("\nid: %d", products[index].code);
    printf("\nNome: %s", products[index].name);
    printf("\nDescricao: %s", products[index].description);
    printf("\nQuantidade: %d", products[index].quantity);
    printf("\nPreco: %.2f", products[index].price);
    printf("\n==========================");
    printf("\n");
}

void showProduct()
{
    system("cls");

    for (int i = 0; i <= productsLength; i++)
    {
        printProduct(i);
    }

    if (productsLength < 0)
    {
        printf("\nSem clientes cadastrados!");
    }

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void showCustumerById()
{
    system("cls");

    int custumerId;

    printf("\nDigite o id do cliente: ");
    scanf(" %d", &custumerId);

    if (custumerId >= 0 && !(custumerId > clientsLength) && !(clientsLength < 0))
    {
        printClient(custumerId);
    }
    else if (clientsLength < 0)
    {
        printf("\nSem clientes cadastrados!");
    }
    else
    {
        printf("\nCodigo invalido!");
    }

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}



#endif