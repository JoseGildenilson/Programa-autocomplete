#include "../include/Autocompletar.hpp"
#include "../include/Termo.hpp"
#include <algorithm>
#include <iomanip>


    //construtur para Autocompletar - Vai ordenadar a lista que virá de ListaOrdenada
Autocompletar::Autocompletar(std::vector<Termo> dados) {

    m_ordenadaAlfabeticamente = dados;
}
    
    
    //setter
void Autocompletar::setPrefixo(std::string prefixo){
    m_prefixo = prefixo;
    
}

void Autocompletar::setK(int k) {
    m_k = k;
}



    //getters
void Autocompletar::imprimirResultados() {
    if (m_ordenadaPorPeso.empty()) {
        std::cout << "Nenhum termo encontrado com esse prefixo.\n";
        return;
    }
    int count = 0;
    for (const Termo& termo : m_ordenadaPorPeso) {

        if (count >= m_k) { 
        break;
    }
        std::cout << std::left << std::setw(16) << termo.getPeso() << termo.getTermo() << std::endl;
        count++;
    }

}

    //metodos em geral


    // busca binaria pela primeira ocorrencia do prefixo na lista ordenada
int Autocompletar::buscarPrimeiraOcorrencia(const std::string& prefixo){
    int esquerda = 0;
    int direita = m_ordenadaAlfabeticamente.size() - 1;
    int resultado = -1; 
    Termo termoBuscar(prefixo, 0);

    while(esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2; 

        int comp = Termo::comparaPrefixo(m_ordenadaAlfabeticamente[meio], termoBuscar, prefixo.size());

        if(comp < 0) {
            esquerda = meio + 1;
        } else {
            if (comp == 0) {
                resultado = meio;
            }
            direita = meio - 1; 
        }
    }

    return resultado;
}


        // busca binaria para encontrar a ultima ocorrencia
int Autocompletar::buscarUltimaOcorrencia(const std::string& prefixo) {
    int esquerda = 0;
    int direita = m_ordenadaAlfabeticamente.size() - 1;
    int resultado = -1; 

    Termo termoBuscar(prefixo, 0);

    while(esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2; 

        int comp = Termo::comparaPrefixo(m_ordenadaAlfabeticamente[meio], termoBuscar, prefixo.size());

        if(comp > 0) { 
            direita = meio - 1;
        } else {
            if(comp == 0){
                resultado = meio;
            }
            esquerda = meio + 1;
        }
    }

    return resultado;
}



 
void Autocompletar::ordenacaoPorPeso(const std::string& prefixo, int k) {
    m_ordenadaPorPeso.clear();


    int inicio = buscarPrimeiraOcorrencia(prefixo);
    int fim = buscarUltimaOcorrencia(prefixo);



    if(inicio == -1 || fim == -1 || inicio > fim || k <= 0) {
        return;
    }

    for (int i = inicio; i <= fim; ++i) {
        m_ordenadaPorPeso.push_back(m_ordenadaAlfabeticamente[i]);
    }

    std::sort(m_ordenadaPorPeso.begin(), m_ordenadaPorPeso.end(), [](const Termo& a, const Termo& b) {
        return Termo::comparaPeso(a, b);
    });
}