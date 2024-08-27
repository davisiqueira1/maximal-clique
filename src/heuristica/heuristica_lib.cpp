#include "heuristica_lib.h"

#include <algorithm>
#include <vector>

Grafo::Grafo(int v) {
    numVertices = v;
    adjacencias.resize(v);
}
void Grafo::addAresta(int u, int v) {
    adjacencias[u].push_back(v);
    adjacencias[v].push_back(u);
}

const std::vector<int>& Grafo::getVizinhos(int v) const {
    return adjacencias[v];
}

// função para verificar se um conjunto de vértices forma uma clique
bool ehClique(const Grafo& grafo, const std::vector<int>& vertices) {
    for (int i = 0; i < vertices.size(); i++) {
        for (int j = i + 1; j < vertices.size(); j++) {
            if (find(grafo.getVizinhos(vertices[i]).begin(),
                     grafo.getVizinhos(vertices[i]).end(),
                     vertices[j]) == grafo.getVizinhos(vertices[i]).end()) {
                return false;
            }
        }
    }
    return true;
}

// ordena os vértices pelo grau em ordem decrescente
bool ordenarVertices(Grafo& grafo, int u, int v) {
    return grafo.getVizinhos(u).size() > grafo.getVizinhos(v).size();
}

std::vector<int> getCliqueMaxima(Grafo& grafo) {
    std::vector<int> clique;

    std::vector<int> vertices(grafo.numVertices);
    for (int i = 0; i < grafo.numVertices; i++) {
        vertices[i] = i;
    }

    sort(vertices.begin(), vertices.end(),
         [&grafo](int u, int v) { return ordenarVertices(grafo, u, v); });

    // tenta adicionar vértices à clique, seguindo a ordem dos graus
    for (int v : vertices) {
        clique.push_back(v);
        if (!ehClique(grafo, clique)) {
            clique.pop_back();
        }
    }

    sort(clique.begin(), clique.end());

    return clique;
}