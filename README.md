# Grafo

Este projeto implementa um grafo utilizando listas de adjacência em C, além de uma fila para auxiliar na busca em largura (BFS). O código permite criar um grafo, adicionar arestas, imprimir a lista de adjacência e realizar a BFS mostrando a árvore de predecessores.

## Estruturas de Dados

### Grafo (`struct grafo`)
```c
    typedef struct grafo {
        int numVertices; 
        Adjacencia *ListaAdj[MAX_VERTICES];
    } Grafo;
```
Representa o grafo propriamente dito.
- `int numVertices`: número total de vértices.
- `Adjacencia *ListaAdj[MAX_VERTICES]`: vetor de ponteiros para listas de adjacência, onde cada posição representa um vértice e aponta para a lista de seus vizinhos.

### Adjacência (`struct adj`)
```c
    typedef struct adj {
        int vertice;
        struct adj *next;
    } Adjacencia;
```
Representa um nó da lista de adjacência de um vértice.
- `int vertice`: número do vértice adjacente.
- `struct adj *next`: ponteiro para o próximo nó da lista.

## Funções do Grafo

### `Grafo *criarGrafo(int vertices)`
Aloca e inicializa um novo grafo com o número de vértices informado. Inicializa todas as listas de adjacência como `NULL`.

### `void imprimirAdjList(Grafo *graph)`
Percorre todos os vértices do grafo e imprime suas listas de adjacência, mostrando para cada vértice quais são seus vizinhos.

### `void addArestas(Grafo *graph, int origem, int destino)`
Adiciona uma aresta do vértice `origem` para o vértice `destino`. Cria um novo nó de adjacência e o insere no início da lista de adjacência do vértice de origem.

### `void BFS(Grafo *graph, int inicio)`
Realiza a busca em largura (BFS) a partir do vértice `inicio`. Utiliza a fila para controlar a ordem de visita dos vértices. Marca os vértices visitados e armazena o predecessor de cada vértice. Ao final, imprime a ordem de visita e a árvore de predecessores.

## Funcionamento Interno

1. **Criação do Grafo:** O usuário informa o número de vértices e arestas. O grafo é criado e as arestas são adicionadas conforme entrada do usuário.
2. **Impressão da Lista de Adjacência:** Mostra para cada vértice todos os seus vizinhos.
3. **Busca em Largura (BFS):** O usuário escolhe um vértice inicial. A BFS percorre o grafo, visitando todos os vértices alcançáveis a partir do inicial, e imprime a ordem de visita e a árvore de predecessores.
4. **Fila:** Utilizada internamente pela BFS para garantir que os vértices sejam visitados na ordem correta.

## Execução

Para compilar e executar:
```sh
make run
```