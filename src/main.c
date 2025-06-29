#include "grafo.h"

int main(){
    int vertices, arestas, origem, destino, inicio;

    printf("Introduza o numero de vertices(ordem): ");
    scanf("%d", &vertices);
    printf("Introduza o numero de arestas(dimensao): ");
    scanf("%d", &arestas);

    Grafo *novoGrafo = criarGrafo(vertices);

    for (int i = 0; i < arestas; i++){
        printf("\nAresta %d\n", i+1);
        printf("Origem: ");
        scanf("%d", &origem);
        printf("Destino: ");
        scanf("%d", &destino);
        addArestas(novoGrafo, origem, destino);
    }

    imprimirAdjList(novoGrafo);
    printf("\n");
    imprimirMatrizAdj(novoGrafo);

    printf("\nVertice de inicio para BFS: ");
    scanf("%d", &inicio);

    BFS(novoGrafo, inicio);
    
    return 0;
}
