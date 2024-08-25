#include "forca_lib.h"

#include <algorithm>

Grafo::Grafo(int v) {
    numVertices = v;
    ma.resize(v);
    for (auto& list : ma) {
        list.assign(numVertices, 0);
    }
}

std::vector<int> getCliqueMaxima(Grafo& grafo) {
    std::vector<int> cliqueMaxima;
    for (int atual = 0; atual < grafo.numVertices; atual++) {
        std::vector<int> vizinhos;
        for (int no = 0; no < grafo.numVertices; no++) {
            if (grafo.ma[atual][no] == 1) {
                vizinhos.push_back(no);
            }
        }

        for (int i = 0; i < vizinhos.size(); i++) {
            std::vector<int> clique = {atual, vizinhos[i]};
            for (int j = 0; j < vizinhos.size(); j++) {
                bool presente = true;
                for (int k = 0; k < clique.size(); k++) {
                    if (grafo.ma[clique[k]][vizinhos[j]] == 0) {
                        presente = false;
                    }
                }
                if (presente) {
                    clique.push_back(vizinhos[j]);
                }
            }
            if (clique.size() > cliqueMaxima.size()) {
                cliqueMaxima = clique;
            }
        }
    }
    sort(cliqueMaxima.begin(), cliqueMaxima.end());
    return cliqueMaxima;
}