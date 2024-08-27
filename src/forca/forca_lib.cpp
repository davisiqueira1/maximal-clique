#include "forca_lib.h"

#include <algorithm>

Grafo::Grafo(int v) {
    numVertices = v;
    ma.resize(v);
    for (auto& list : ma) {
        list.assign(numVertices, 0);
    }
}

bool isClique(const Grafo& grafo, const std::vector<int>& conjunto) {
    int tamanho = conjunto.size();
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (grafo.ma[conjunto[i]][conjunto[j]] == 0) {
                return false;
            }
        }
    }
    return true;
}

std::vector<int> encontrarCliqueMaxima(const Grafo& grafo) {
    int n = grafo.ma.size();
    std::vector<int> maior_clique;

    // Gera todos os subconjuntos possíveis
    for (int i = 0; i < (1 << n); i++) {
        std::vector<int> conjunto;

        // Cria um subconjunto de vértices com base em i
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                conjunto.push_back(j);
            }
        }

        // Verifica se o subconjunto atual é uma clique
        if (isClique(grafo, conjunto)) {
            if (conjunto.size() > maior_clique.size()) {
                maior_clique = conjunto;
            }
        }
    }
    sort(maior_clique.begin(), maior_clique.end());

    return maior_clique;
}