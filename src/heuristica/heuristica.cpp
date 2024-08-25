#include <iostream>

#include "heuristica_lib.h"

using namespace std;

int main() {
    int numVertices, numArestas;

    cin >> numVertices >> numArestas;
    Grafo grafo(numVertices);

    for (int i = 0; i < numArestas; i++) {
        int u, v;
        cin >> u >> v;
        grafo.addAresta(u, v);
    }

    vector<int> cliqueMaxima = getCliqueMaxima(grafo);

    for (int v : cliqueMaxima) {
        cout << v << " ";
    }
    cout << endl;

    cout << "n=" << cliqueMaxima.size() << endl;

    return 0;
}