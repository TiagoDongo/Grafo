#include"grafo.h"
#include"fila.h"

//função que cria o grafo
Grafo *criarGrafo(int vertices){
    //alocação de memoria para o grafo
    Grafo *graph = (Grafo*)malloc(sizeof(Grafo));
    if (graph == NULL){ //verificação da alocação
        return NULL;
    }
    
    //define o numero de vertices
    graph->numVertices = vertices;

    // Inicializa os ponteiros das listas de adjacência como NULL
    for (int i = 0; i < vertices; i++){
        graph->ListaAdj[i] = NULL;
    }

    return graph;    
}

// Função para imprimir a lista de adjacência do grafo
void imprimirAdjList(Grafo *graph){
    if (graph == NULL){ //verificação do grafo se esta vazia
        printf("ERRO: grafo sem elementos.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nLista de Adjacencia: \n");
    for (int i = 0; i < graph->numVertices; i++){
        printf("[%d]: ",i);
        Adjacencia *aux = graph->ListaAdj[i];
        // Percorre a lista de adjacência do vértice i
        while (aux){
            printf("[ %d ] - ", aux->vertice);
            aux = aux->next;
        }
        printf("\n");
    }    
}

// Função para adicionar uma aresta ao grafo
void addArestas(Grafo *graph, int origem, int destino){
    //aloca espaço para a nova adjacencia
    Adjacencia *newAdj = (Adjacencia*)malloc(sizeof(Adjacencia));

    //verifica se a alocação foi feita corretamente
    if (newAdj == NULL){
        printf("ERRO de alocacao.\n");
        exit(EXIT_FAILURE);
    }
    
    newAdj->vertice = destino;
    // Insere a nova adjacência no início da lista do vértice de origem
    newAdj->next = graph->ListaAdj[origem];
    graph->ListaAdj[origem] = newAdj;
}

// Função para realizar a busca em largura (BFS) no grafo
void BFS(Grafo *graph, int inicio){
    /*
    verticeVisitado - marca se um vertice ja foi explorado(1) ou não (0)
    verticePredecessor - guarda quem descobriu cada vértice durante a travessia.
    */
    int verticeVisitado[MAX_VERTICES], verticePredecessor[MAX_VERTICES];

    //inivializa todos os predecessores como -1 (sem pai)
    for (int i = 0; i < graph->numVertices; i++){
        verticePredecessor[i] = -1;
        verticeVisitado[i] = 0;
    }

    //criação de uma fila para controlar a ordem de visita dos vértices
    F *fila = FilaInit(graph->numVertices);
    verticeVisitado[inicio] = 1; //marca vertice visitado como 1(visitado)
    FilaPut(fila, inicio); //Coloca o vértice inicial na fila
    
    printf("\nOrdem de visita (BFS): ");
    //executa enquanto hover vertices na fila
    while (!FilaEmpty(fila)){ 
        int atual = FilaGet(fila); //remove o proximo vertice da fila
        printf("%d ", atual);

        // Percorre todos os vizinhos do vértice atual
        Adjacencia *adj = graph->ListaAdj[atual];
        while (adj != NULL){
            int vizinho = adj->vertice;
            // Se o vizinho ainda não foi visitado
            if (!verticeVisitado[vizinho]){
                verticeVisitado[vizinho] = 1;
                verticePredecessor[vizinho] = atual;
                FilaPut(fila, vizinho); // Adiciona o vizinho na fila
            }
            adj = adj->next; //avança para o proximo adjacente
        }
    }
    
    // Imprime a árvore de predecessores gerada pela BFS
    printf("\n\nArvore de Predecessores (BFS):\n");
    printf("Vertice | Predecessor\n");
    printf("----------------------\n");

    //executa enquanto i for menor que o numero de verticces
    for (int i = 0; i < graph->numVertices; i++){
        if (i == inicio) // se i for igual ao inicio então é a raiz
            printf("   %d    |   raiz\n", i);
        else if (verticeVisitado[i])
            printf("   %d    |   %d\n", i, verticePredecessor[i]);
        else
            printf("   %d    |   (nao alcancado)\n", i);
    }

    Dump(fila); 
}