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
    char description[100];
    int quantity;
    float price;
};

extern struct Client clients[MAX_LENGHT];
extern int clientsLength;

extern struct Product products[MAX_LENGHT];
extern int productsLength;

#endif