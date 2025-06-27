#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct fila F;
typedef int Item;

typedef struct _element{
    Item item;
    struct _element * next;
} element;

struct fila{
    element * primeiro;
    element * ultimo;
};

element *FilaNew(Item vItem, element *pNext);

F *FilaInit(int maxN);

void FilaPut(F *pFila, Item vI);

Item FilaGet(F *pFila);


Item PeekFirst(F *pFila);

Item PeekLast(F *pFila);

void Dump(F *pFila);

int FilaEmpty(F *pFila);

void PrintFila(F *pFila);
void menu(F *pFila);
#endif