#ifndef GRAFO_H_INCLUDED 
#define GRAFO_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100 //numero maximo de vertices

//Estrutura que representa uma lista de adjacencia
typedef struct adj {
    int vertice; //guarda o numero do vertice adjacente
    struct adj *next; //aponta para o proximo da lista
} Adjacencia;

typedef struct grafo {
    int numVertices; //numero total de vertices
    Adjacencia *ListaAdj[MAX_VERTICES]; //vetor de ponteiros para a lista de adjacencia
} Grafo;

//função que cria o grafo
Grafo *criarGrafo(int vertices);

//função para imprimir a lista de adjacencia
void imprimirAdjList(Grafo *graph);

//função para adicionar arestas 
void addArestas(Grafo *graph, int origem, int destino);

void BFS(Grafo *graph, int inicio);
#endif