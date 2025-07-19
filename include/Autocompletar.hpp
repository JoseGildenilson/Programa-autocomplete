#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include <vector>
#include <iostream>
#include "Termo.hpp"
#include <string>



class Autocompletar {
private:
    std::vector<Termo> m_ordenadaAlfabeticamente;
    std::vector<Termo> m_ordenadaPorPeso;
    std::string m_prefixo;
    int m_k; // inteiro que informa a quantidade de elementos que será imprimida para o usuário
public:
    //construtur para Autocompletar - Vai ordenadar a lista que virá de ListaOrdenada
    Autocompletar(std::vector<Termo> dadas);

    //setters
    void setPrefixo(std::string prefixo);
    void setK(int k);

    //getters
    void imprimirResultados(); // metodo para imprimir o autocomplete 

    //metodos em geral
        // busca binaria pela primeira ocorrencia do prefixo na lista ordenada
    int buscarPrimeiraOcorrencia(const std::string& prefixo);
        // busca binaria para encontrar a ultima ocorrencia do prefixo na lista ordenada
    int buscarUltimaOcorrencia(const std::string& prefixo);
        // Fazer a ordenação por peso e atribuir ao atributo m_ordenação por peso
    void ordenacaoPorPeso(const std::string& prefixo, int k);
};


#endif