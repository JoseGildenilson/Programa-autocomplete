#ifndef LISTAORDENADA_HPP
#define LISTAORDENADA_HPP

#include "Lista.hpp"
#include <algorithm>

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
    // Ordena usando operador < do próprio tipo T
    void ordenar() {
        std::sort(this->dados.begin(), this->dados.end());
    }

    // Ordena usando uma função de comparação customizada
    void ordenar(bool (*comparador)(const T&, const T&)) {
        std::sort(this->dados.begin(), this->dados.end(), comparador);
    }

    // Reverte a ordem da lista
    void reverter() {
        std::reverse(this->dados.begin(), this->dados.end());
    }
};

#endif
