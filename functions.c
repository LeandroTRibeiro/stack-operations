#ifndef FUNCTIONS_C
#define FUNCTIONS_C

#include "structs.h"
#include "constants.h"
#include "libs.h"

struct Stack s;

struct Client clients[MAX_LENGHT];
int clientsLength = 0;

struct Product products[MAX_LENGHT];
int productsLength = 0;

struct Sale sales[MAX_LENGHT];
int salesLength = 0;

int isFull(struct Stack *s) {
    return s->top == MAX_LENGHT - 1;
}

void initialize(struct Stack *s) {
    s->top = -1; 
}

void push(struct Stack *s, struct Sale *sales) {
    if (isFull(s)) {
        printf("Erro: A pilha está cheia!\n");
    } else {
        s->items[++s->top] = *sales; 
        printf("Item %d empilhado!\n", sales->code);
    }
}

struct Sale* peek(struct Stack *s) {
    if (s->top == -1) {
        printf("Erro: A pilha está vazia!\n");
        return NULL;  
    } else {
        return &s->items[s->top];  
    }
}

struct Sale* pop(struct Stack *s) {
    if (s->top == -1) {  
        printf("Erro: A pilha está vazia, não há vendas para remover!\n");
        return NULL;  
    } else {
        return &s->items[s->top--];  
    }
}

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

    for (int i = 1; i <= clientsLength; i++)
    {
        printClient(i);
    }

    if (clientsLength < 1)
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

    for (int i = 1; i <= productsLength; i++)
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

void showClientById()
{
    system("cls");

    int clientId;

    printf("\nDigite o id do cliente: ");
    scanf(" %d", &clientId);

    if (clientId >= 1 && !(clientId > clientsLength) && !(clientsLength < 1))
    {
        printClient(clientId);
    }
    else if (clientsLength < 1)
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

void printSale(struct Sale *sale) {

    printf("\n");
    printf("\n== Cliente ========================");
    printf("\nid: %d", sale->client.code);
    printf("\nNome: %s", sale->client.name);
    printf("\n===================================");
    printf("\n");
    printf("\n== Produtos ========================");

    for(int i = 1; i <= sale->productSalesLength; i++) {

        printf("\n====================================");
        printf("\nid: %d", sale->productsSales[i].product.code);
        printf("\nNome: %s", sale->productsSales[i].product.name);
        printf("\nDescricao: %s", sale->productsSales[i].product.description);
        printf("\nPreco Unitario: %.2f", sale->productsSales[i].product.price);
        printf("\nQuantidade: %d", sale->productsSales[i].quantity);
        printf("\n====================================");
    }

    printf("\nValor total da venda: %.2f", sale->price);
    printf("\n");
}

void inserSale(struct Stack *s)
{

    system("cls");

    salesLength++;

    int clientId;
    int invalidClient = 0;

    sales[salesLength].code = salesLength;
    sales[salesLength].productSalesLength = 1;
    sales[salesLength].price = 0;

    do
    {
        printf("\nDigite o id do client: ");
        scanf(" %d", &clientId);

        if (clients[clientId].code)
        {
            printClient(clientId);
            printf("\nCliente adicionado com sucesso!");
            invalidClient = 0;

            sales[salesLength].client = clients[clientId];
        }
        else
        {
            printf("\nCliente invalido!");
            invalidClient = 1;
        }

    } while (invalidClient == 1);

    int addMoreProducts = 0;

    do {

        int productId;
        int invalidProduct = 0;

        do {
            printf("\nDigite o id do produto: ");
            scanf(" %d", &productId);

            if(products[productId].code && products[productId].quantity > 0) {

                printProduct(productId);
                printf("\nProduto selecionado com sucesso!");
                invalidProduct = 0;

                sales[salesLength].productsSales[sales[salesLength].productSalesLength].product = products[productId];

            } else {

                printf("\nProduto invalido!");
                invalidProduct = 1;
            }
        } while(invalidProduct == 1);

        int quantity;
        int invalidQuantity = 0;

        do {

            printf("\nDigite a quantidade do produto: ");
            scanf(" %d", &quantity);

            if(products[productId].quantity && products[productId].quantity >= quantity) {

                printf("\nQuantidade valida!");
                printf("\nProduto adiciona com sucesso!");

                invalidQuantity = 0;

                sales[salesLength].productsSales[sales[salesLength].productSalesLength].quantity = quantity;

                sales[salesLength].price += products[productId].price * quantity;

                products[productId].quantity -= quantity;

            } else {

                printf("\nQuantidade invalida!");
                invalidQuantity = 1;
            };

        } while(invalidQuantity == 1);

        char option;
        int invalidOption = 0;

        do {
            printf("\nDeseja adicionar mais produtos: ( S / N ) ");
            scanf(" %c", &option);

            option = tolower(option);

            if(option == 's') {

                invalidOption = 0;
                addMoreProducts = 1;
                sales[salesLength].productSalesLength++;

            } else if(option == 'n') {

                addMoreProducts = 0;
                invalidOption = 0;

            } else {

                printf("\nOpcao invalida!");
                invalidOption = 1;
            }

        } while(invalidOption == 1);

    } while(addMoreProducts == 1);

    system("cls");
    push(s, &sales[salesLength]);
    printf("\nVenda criada com sucesso!");
    printSale(&sales[salesLength]);
    salesLength++;

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

}

void showSales(struct Stack *s) {

    system("cls");

    if (s->top == -1) {
        printf("\nA pilha de vendas está vazia!\n");
    } else {
        printf("\n==== Vendas na pilha ====\n");
        for (int i = s->top; i >= 0; i--) {
            printSale(&s->items[i]);
        }
    }

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();
}

void showSale(struct Stack *s) {

    system("cls");

    printf("\n==== Ultima Venda na pilha ====\n");

    printSale(peek(s));

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();
};

void removeSale(struct Stack *s) {

    system("cls");

    printf("\n==== Venda removida da pilha ====\n");

    printSale(pop(s));

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();
}

#endif