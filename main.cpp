#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "include/Autocompletar.hpp"
#include "include/Termo.hpp"
#include "include/ListaOrdenada.hpp"
#include "include/Lista.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <arquivo.txt> <tamanhoLista>\n";
        return 1;
    }

    string nomeArquivo = argv[1];
    int tamanhoLista = stoi(argv[2]);

    ifstream entradaArquivo(nomeArquivo);
    if (!entradaArquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return 1;
    }

    ListaOrdenada<Termo> lista; // Correção aqui
    string linha;

    while (getline(entradaArquivo, linha)) {
        istringstream iss(linha);
        long peso;
        string termo;

        if (!(iss >> peso)) {
            cerr << "Erro ao ler peso na linha: " << linha << endl;
            continue;
        }

        getline(iss >> ws, termo);
        Termo t(termo, peso);
        lista.inserir(t);
    }

    entradaArquivo.close();

    // Agora ordena alfabeticamente usando operador <
    lista.ordenar();

    // Constrói o autocompletar com a lista ordenada
    Autocompletar sistema(lista.getDados());
    sistema.setK(tamanhoLista);

    string prefixo;
    while (true) {
        cout << "Entre com o termo a ser auto-completado (digite \"sair\" para encerrar o programa): " << endl;
        getline(cin, prefixo);

        if (prefixo == "sair")
            break;

        sistema.setPrefixo(prefixo);
        sistema.ordenacaoPorPeso(prefixo, tamanhoLista);
        sistema.imprimirResultados();
    }
    return 0;
}
