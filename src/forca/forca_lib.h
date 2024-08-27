#include <vector>

struct Grafo {
    int numVertices;
    std::vector<std::vector<int>> ma;
    Grafo(int v);
};

bool isClique(const Grafo& grafo, const std::vector<int>& conjunto);
std::vector<int> encontrarCliqueMaxima(const Grafo& grafo);