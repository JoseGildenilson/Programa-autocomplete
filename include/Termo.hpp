#ifndef TERMO_HPP
#define TERMO_HPP

#include <string>
#include <vector>

class Termo {
private:
    std::string termo;
    long peso;

public:
    // Construtor padrão necessário para vector
    Termo() : termo(""), peso(0) {}

    // Construtor parametrizado
    Termo(std::string termo, long peso);

    // Get termo
    std::string getTermo() const;

    // Get peso
    long getPeso() const;


    // Sobrecarga do operador para ordenação alfabética
    bool operator<(const Termo& outro) const;

    // Comparadores estáticos
    static int comparaPrefixo(const Termo& meuTermo, const Termo& outroTermo, int r);
    static bool comparaPeso(const Termo& meuTermo, const Termo& outroTermo);
};

#endif
