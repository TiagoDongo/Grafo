#include"fila.h"

element *FilaNew(Item vItem, element *pNext){
    element *x = (element *) malloc(sizeof (element));
    x->item = vItem;
    x->next = pNext;
    return x;
}

F *FilaInit(int maxN){
    F *pFila = (F*) malloc(sizeof(F));
    pFila->primeiro = pFila->ultimo = NULL;
    return pFila;
}

void FilaPut(F *pFila, Item vI){
    if (pFila->primeiro == NULL) { /* a fila está vazia */
        pFila->ultimo = FilaNew(vI, pFila->primeiro);
        pFila->primeiro = pFila->ultimo; return; 
    }
    /* o item é colocado no fim da lista */
    pFila->ultimo->next = FilaNew(vI, NULL);
    pFila->ultimo = pFila->ultimo->next;
}

Item FilaGet(F *pFila){
    Item item = pFila->primeiro->item;
    element *elem = pFila->primeiro->next;
    free(pFila->primeiro);
    pFila->primeiro = elem;
    return item;
}

void PrintFila(F *pFila){
    element *aux = pFila->primeiro;
    while (aux != NULL){
        printf("%d \t", aux->item);
        aux = aux->next;
    }
    printf("\n");
}

int FilaEmpty(F *pFila){
    return pFila->primeiro==NULL;
}

Item PeekFirst(F *pFila){
        return pFila->primeiro->item;    
}

Item PeekLast(F *pFila){
        return pFila->ultimo->item;
}

void Dump(F *pFila){
    element *aux = pFila->primeiro;
    while (aux != NULL){
        element *temp = aux;
        aux = aux->next;
        free(temp);
    }
    pFila->primeiro = NULL;
    pFila->ultimo = NULL;

    free(pFila);
}