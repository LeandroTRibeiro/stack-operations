#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"
#include "constants.h"
#include "libs.h"

struct Custumer custumers[MAX_LENGHT];
struct Produto produto[MAX_LENGHT];

int custumerLength = -1;
int produtoLength = -1;


void initialize(struct Stack *s) {
    system("cls");
    
    s->top = -1;

    printf("\nPilha Inicializada!\n");

    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();
};

int isFull(struct Stack *s) {
    return(s->top == MAX_LENGHT -1);
}

int isEmpty(struct Stack *s) {
    return(s->top == -1);
}

void push(struct Stack *s) {
    int num;

    system("cls");

    if(isFull(s)) {
        printf("\nPilha cheia, faça um pop!\n");
        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();
    } else {

        printf("\nDigite o valor que deseja adicionar a pilha: \n");
        scanf(" %d", &num);

        s->items[++s->top] = num;

        printf("\nValor empilhado com sucesso! %d\n", num);

        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();
    }
}

void pop(struct Stack *s) {
    system("cls");
    if(isEmpty(s)) {

        printf("\nPilha vazia, faça um push!\n");
        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();

    } else {

        printf("\nValor desempilhado com sucesso! %d\n", s->items[s->top]);

        s->items[s->top--];

        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();
    }
}

void peek(struct Stack *s) {
    system("cls");
    if(isEmpty(s)) {
        printf("\nPilha vazia!, faça um push!\n");
        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();
    } else {
        printf("\nTopo da pilha : %d\n", s->items[s->top]);
        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();
    }
}

void showStack(struct Stack *s) {
    system("cls");
    if(isEmpty(s)) {

        printf("\nPilha vazia, faça um push!\n");
        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();

    } else {
        printf("\nPilha: ");
        for (int i = s->top; i >= 0; i--) {
            printf("\n%d", s->items[i]);
        }
        printf("\n");
        printf("\nPressione qualquer tecla para voltar ao menu.");
        getchar();
        getchar();
    }
}

void insertCustumer() {
    system("cls");

    custumerLength++;

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", custumers[custumerLength].name);

    custumers[custumerLength].code = custumerLength;

    printf("\nCliente cadastrado com sucesso!");
    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void insertProduct() {
    system("cls");

    produtoLength++;

    printf("Digite a descricao do produto: ");
    scanf(" %[^\n]", produto[produtoLength].desc);
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d", &produto[produtoLength].qtd);
    printf("Digite o preco do produto: ");
    scanf("%f", &produto[produtoLength].preco);

    produto[produtoLength].codigo = produtoLength;

    printf("\nProduto cadastrado com sucesso!");
    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void showCustumers() {
    system("cls");


    for(int i = 0; i <= custumerLength; i++) {
        printf("\n");
        printf("\n==========================");
        printf("\nid: %d", custumers[i].code);
        printf("\nNome: %s", custumers[i].name);
        printf("\n==========================");
        printf("\n");
    }

    if(custumerLength < 0) {
        printf("\nSem clientes cadastrados!");
    }

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void showProduct() {
    system("cls");

    for(int i = 0; i <= produtoLength; i++) {
        printf("\n");
        printf("\n==========================");
        printf("\nid: %d", produto[i].codigo);
        printf("\nDescricao: %s", produto[i].desc);
        printf("\nQuantidade: %d", produto[i].qtd);
        printf("\nPreco: %.2f", produto[i].preco);
        printf("\n==========================");
        printf("\n");
    }

    if(produtoLength < 0) {
        printf("\nSem clientes cadastrados!");
    }

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}

void showCustumerById() {
    system("cls");

    int custumerId;

    printf("\nDigite o id do cliente: ");
    scanf(" %d", &custumerId);

    if(custumerId >= 0  && !(custumerId > custumerLength) && !(custumerLength < 0)) {
        printf("\n");
        printf("\n==========================");
        printf("\nid: %d", custumers[custumerId].code);
        printf("\nNome: %s", custumers[custumerId].name);
        printf("\n==========================");
        printf("\n");    
    } else if (custumerLength < 0) {
        printf("\nSem clientes cadastrados!");
    } else {
        printf("\nCodigo invalido!");
    }

    printf("\n");
    printf("\nPressione qualquer tecla para voltar ao menu.");
    getchar();
    getchar();

    return;
}


#endif