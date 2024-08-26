#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

void gerarGrafoAleatorio(int numVertices, int numArestas, vector<pair<int, int>>& arestas) {
    set<pair<int, int>> arestasUnicas; // Conjunto para garantir que as arestas sejam únicas.

    while (arestasUnicas.size() < numArestas) { // Gera arestas até que o número desejado seja atingido.
        int u = rand() % numVertices; // Gera um vértice aleatório u.
        int v = rand() % numVertices; // Gera um vértice aleatório v.

        if (u != v) { // Garante que não haverá uma aresta de um vértice para ele mesmo.
            if (u > v) swap(u, v); // Ordena os vértices para garantir que (u, v) e (v, u) sejam tratados como a mesma aresta.
            arestasUnicas.insert({u, v}); // Adiciona a aresta ao conjunto.
        }
    }

    arestas.assign(arestasUnicas.begin(), arestasUnicas.end()); // Copia as arestas únicas para o vetor.
}

// Função para salvar o grafo gerado em um arquivo.
void salvarEntrada(const string& nomeArquivo, int numVertices, const vector<pair<int, int>>& arestas) {
    ofstream arquivo(nomeArquivo); // Abre o arquivo para escrita.

    if (arquivo) { // Verifica se o arquivo foi aberto com sucesso.
        arquivo << numVertices << " " << arestas.size() << endl; // Escreve o número de vértices e arestas.
        for (const auto& aresta : arestas) { // Itera sobre todas as arestas.
            arquivo << aresta.first + 1 << " " << aresta.second + 1 << endl; // Escreve cada aresta somada mais 1.
        }
    } else {
        cout << "Não foi possível abrir o arquivo " << nomeArquivo << endl; // Mensagem de erro se o arquivo não puder ser aberto.
    }
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios com base no tempo atual.

    int minVertices = 5; // Valor mínimo para o número de vértices.
    int maxVertices = 50; // Valor máximo para o número de vértices.
    
    // Gera um número aleatório de vértices dentro do intervalo [minVertices, maxVertices].
    int numVertices = rand() % (maxVertices - minVertices + 1) + minVertices;
    
    // Gera um número aleatório de arestas dentro do intervalo permitido.
    int numArestas = rand() % ((numVertices * (numVertices - 1)) / 2 - (numVertices - 1)) + (numVertices - 1);
    
    vector<pair<int, int>> arestas; // Vetor para armazenar as arestas do grafo.
    
    gerarGrafoAleatorio(numVertices, numArestas, arestas); // Gera o grafo aleatório.

    salvarEntrada("testes/entrada.txt", numVertices, arestas); // Salva o grafo gerado em um arquivo.

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso.
}
