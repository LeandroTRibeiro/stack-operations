#ifndef STRUCTS_H
#define STRUCTS_H

#include "constants.h"

struct Stack {
    int items[MAX_LENGHT];
    int top;
};

struct Custumer {
    char name[100];
    int code;
};

struct Produto{
    char desc[100];
    int codigo;
    int qtd;
    float preco;
};

extern struct Stack s;
extern struct Custumer custumers[MAX_LENGHT];
extern int custumerLength;
extern struct Produto produto[MAX_LENGHT];
extern int produtoLength;


#endif