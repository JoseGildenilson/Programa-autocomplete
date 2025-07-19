#include "../include/Termo.hpp" 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Método de construção do objeto parametrizado
Termo::Termo(std::string termo, long peso) {
    this->termo = termo;
    this->peso = peso;
};

// Getter de termo
std::string Termo::getTermo() const {
    return termo;
}

// Getter de peso
long Termo::getPeso() const {
    return peso;
}

// Sobrecarga do operador
bool Termo::operator<(const Termo& outro) const {
    return this->termo < outro.termo;
}

// Primeiro método de comparação - Prefixo
int Termo::comparaPrefixo(const Termo& meuTermo, const Termo& outroTermo, int r) {
    std::string prefixoMeu = meuTermo.termo.substr(0, r);
    std::string prefixoOutro = outroTermo.termo.substr(0, r);

    if (prefixoMeu > prefixoOutro) {
        return 1;
    } else if (prefixoMeu == prefixoOutro) {
        return 0;
    } else {
        return -1;
    }
}

// Segundo método de comparação - Peso
bool Termo::comparaPeso(const Termo& meuTermo, const Termo& outroTermo) {
    return meuTermo.peso > outroTermo.peso;
}


