#ifndef STRUCTS_H
#define STRUCTS_H

#include "constants.h"

struct Client
{
    int code;
    char name[100];
};

struct Product
{
    int code;
    char name[100];
    char description[100];
    int quantity;
    float price;
};

struct ProductSale {
    struct Product product;
    int quantity;
};

struct Sale {
    int code;
    struct Client client;
    struct ProductSale productsSales[100];
    int productSalesLength;
    float price;
};

struct Stack {
    struct Sale items[100];
    int top;
};

extern struct Client clients[MAX_LENGHT];
extern int clientsLength;

extern struct Product products[MAX_LENGHT];
extern int productsLength;

extern struct Sale sales[MAX_LENGHT];
extern int salesLength;

extern struct Stack s;

#endif