#include <vector>

struct Grafo {
    int numVertices;
    std::vector<std::vector<int>> ma;
    Grafo(int v);
};

std::vector<int> getCliqueMaxima(Grafo& grafo);