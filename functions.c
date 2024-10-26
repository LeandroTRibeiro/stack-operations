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

    printf("Digite o nome do cliente: ");
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

    printf("Digite a descricao do produto: ");
    scanf(" %[^\n]", products[productsLength].description);
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d", &products[productsLength].quantity);
    printf("Digite o preco do produto: ");
    scanf("%f", &products[productsLength].price);

    products[productsLength].code = productsLength;

    printf("\nProduto cadastrado com sucesso!");
    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void showCustumers()
{
    system("cls");

    for (int i = 0; i <= clientsLength; i++)
    {
        printf("\n");
        printf("\n==========================");
        printf("\nid: %d", clients[i].code);
        printf("\nNome: %s", clients[i].name);
        printf("\n==========================");
        printf("\n");
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

void showProduct()
{
    system("cls");

    for (int i = 0; i <= productsLength; i++)
    {
        printf("\n");
        printf("\n==========================");
        printf("\nid: %d", products[i].code);
        printf("\nDescricao: %s", products[i].description);
        printf("\nQuantidade: %d", products[i].quantity);
        printf("\nPreco: %.2f", products[i].price);
        printf("\n==========================");
        printf("\n");
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
        printf("\n");
        printf("\n==========================");
        printf("\nid: %d", clients[custumerId].code);
        printf("\nNome: %s", clients[custumerId].name);
        printf("\n==========================");
        printf("\n");
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