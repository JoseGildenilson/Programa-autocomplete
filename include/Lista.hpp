#ifndef LISTA_HPP
#define LISTA_HPP

#include <vector>
#include <iostream>

template <typename T>
class Lista {
protected:
    std::vector<T> dados;

public:
    void inserir(const T& elemento) {
        dados.push_back(elemento);
    }

    int tamanho() const {
        return dados.size();
    }

    void imprimir() const {
        for (const auto& elemento : dados) {
            std::cout << elemento << std::endl;
        }
    }

    T& operator[](int indice) {
        return dados[indice];
    }

    const T& operator[](int indice) const {
        return dados[indice];
    }

    std::vector<T>& getDados() {
        return dados;
    }

    const std::vector<T>& getDados() const {
        return dados;
    }
};

#endif
