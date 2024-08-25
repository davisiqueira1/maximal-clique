#include <vector>

struct Grafo {
    int numVertices;
    std::vector<std::vector<int>> adjacencias;

    Grafo(int v);
    void addAresta(int u, int v);
    const std::vector<int>& getVizinhos(int v) const;
};

// função para verificar se um conjunto de vértices forma uma clique
bool ehClique(const Grafo& grafo, const std::vector<int>& vertices);

// ordena os vértices pelo grau em ordem decrescente
bool ordenarVertices(Grafo& grafo, int u, int v);

std::vector<int> getCliqueMaxima(Grafo& grafo);