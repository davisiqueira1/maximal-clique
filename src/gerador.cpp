#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

// Gera um grafo aleatório com um número específico de vértices e arestas
void gerarGrafoAleatorio(int numVertices, int numArestas, vector<pair<int, int>>& arestas) {
    set<pair<int, int>> arestasUnicas; // Conjunto para armazenar arestas únicas

    // Gera arestas até atingir o número desejado
    while (arestasUnicas.size() < numArestas) {
        int u = rand() % numVertices; // Vértice inicial
        int v = rand() % numVertices; // Vértice final

        if (u != v) { // Garante que a aresta não se conecta a um mesmo vértice
            if (u > v) swap(u, v); // Ordena os vértices
            arestasUnicas.insert({u, v}); // Adiciona a aresta ao conjunto
        }
    }

    arestas.assign(arestasUnicas.begin(), arestasUnicas.end()); // Copia as arestas para o vetor
}

// Salva o grafo gerado em um arquivo
void salvarEntrada(const string& nomeArquivo, int numVertices, const vector<pair<int, int>>& arestas) {
    ofstream arquivo(nomeArquivo); // Abre o arquivo para escrita

    if (arquivo) { // Verifica se o arquivo foi aberto corretamente
        arquivo << numVertices << " " << arestas.size() << endl; // Escreve o número de vértices e arestas
        for (const auto& aresta : arestas) {
            arquivo << aresta.first + 1 << " " << aresta.second + 1 << endl; // Escreve cada aresta
        }
    } else {
        cout << "Não foi possível abrir o arquivo " << nomeArquivo << endl; // Mensagem de erro
    }
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    int minVertices = 5; // Valor mínimo para o número de vértices
    int maxVertices = 30; // Valor máximo para o número de vértices
    
    int numVertices = rand() % (maxVertices - minVertices + 1) + minVertices; // Número aleatório de vértices
    int numArestas = rand() % ((numVertices * (numVertices - 1)) / 2 - (numVertices - 1)) + (numVertices - 1); // Número aleatório de arestas
    
    vector<pair<int, int>> arestas;
    
    gerarGrafoAleatorio(numVertices, numArestas, arestas);

    salvarEntrada("testes/entrada.txt", numVertices, arestas);

    return 0;
}
