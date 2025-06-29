#ifndef GRAFO_H_INCLUDED 
#define GRAFO_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100 //numero maximo de vertices


/**
 * @brief Estrutura que representa uma lista de adjacencia
 */
typedef struct adj {
    int vertice; ///< guarda o numero do vertice adjacente
    struct adj *next; ///< aponta para o proximo da lista
} Adjacencia;


/**
 * @brief Estrutura que representa o grafo.
 */
typedef struct grafo {
    int numVertices; ///< numero total de vertices
    Adjacencia *ListaAdj[MAX_VERTICES]; ///< vetor de ponteiros para a lista de adjacencia
} Grafo;

/**
 * @brief Cria e inicializa um novo grafo com o número de vértices informado.
 * @param vertices Número de vértices do grafo.
 * @return Ponteiro para o grafo criado.
 */
Grafo *criarGrafo(int vertices);

/**
 * @brief Imprime a lista de adjacencia do grafo
 * @param graph Pnteito para o grafo
 */
void imprimirAdjList(Grafo *graph);

/**
 * @brief Adiciona uma aresta do vértice `origem` para o vértice `destino`
 * @param graph Ponteiro para o grafo
 * @param origem Vértice de origem
 * @param destino Vértice de destino
 */
void addArestas(Grafo *graph, int origem, int destino);

/**
 * @brief Realiza a busca em largura (BFS) a partir de um vértice inicial.
 * @param graph Ponteiro para o grafo.
 * @param inicio Vértice inicial da busca.
 */
void BFS(Grafo *graph, int inicio);

//Função para imprimir a matriz de incidencia do grafo
void imprimirMatrizAdj(Grafo *graph);
#endif