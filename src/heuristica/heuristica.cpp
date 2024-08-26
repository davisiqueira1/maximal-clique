#include <iostream>
#include <chrono>

#include "heuristica_lib.h"

using namespace std;

int main() {
    int numVertices, numArestas;
    cin >> numVertices >> numArestas;
    Grafo grafo(numVertices);

    for (int i = 0; i < numArestas; i++) {
        int u, v;
        cin >> u >> v;
        grafo.addAresta(u - 1, v - 1);
    }
    auto t1 = chrono::high_resolution_clock::now();
    vector<int> cliqueMaxima = getCliqueMaxima(grafo);
    auto t2 = chrono::high_resolution_clock::now();
    for (int v : cliqueMaxima) {
        cout << v + 1 << " ";
    }
    cout << endl;
    chrono::duration<double, std::milli> ms_double = t2 - t1;
    cout << "Tempo: " << ms_double.count() << "ms" << endl;
    cout << "n=" << cliqueMaxima.size() << endl;

    return 0;
}
