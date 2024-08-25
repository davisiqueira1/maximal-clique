#include <iostream>

#include "forca_lib.h"

using namespace std;

int main() {
    int numVertices, numArestas;

    cin >> numVertices >> numArestas;
    Grafo grafo(numVertices);

    for (int i = 0; i < numArestas; i++) {
        int u, v;
        cin >> u >> v;
        grafo.ma[u - 1][v - 1] = 1;
        grafo.ma[v - 1][u - 1] = 1;
    }

    vector<int> cliqueMaxima = getCliqueMaxima(grafo);

    for (int i = 0; i < cliqueMaxima.size(); i++) {
        cout << cliqueMaxima[i] + 1 << " ";
    }
    cout << endl;

    cout << "n=" << cliqueMaxima.size() << endl;

    return 0;
}