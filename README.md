# Projeto Autocompletar - Preenchimento Automático em C++

## Descrição

Este projeto implementa um sistema de preenchimento automático (_autocomplete_) para um conjunto de termos com pesos associados. Dado um prefixo digitado pelo usuário, o programa retorna os termos que começam com esse prefixo, ordenados em ordem decrescente pelo peso. 

A ideia é simular funcionalidades comuns em buscadores e sistemas modernos que oferecem sugestões inteligentes conforme o usuário digita, como no Google, IMDb, entre outros.

O projeto foi desenvolvido como trabalho final para a disciplina de Linguagem de Programação 1, com foco em:

- Utilização de templates em C++ para criar listas genéricas e ordenadas.
- Implementação de busca binária para eficiência na pesquisa de termos.
- Ordenação customizada utilizando funções de comparação.
- Organização modular com classes específicas para termos, listas e autocompletar.

---

## Estrutura do Projeto

- **`Termo`**: classe que representa um termo e seu peso, com métodos para comparação e sobrecarga de operadores.
- **`ListaOrdenada<T>`**: template para uma lista genérica que permite ordenação baseada em critérios customizados.
- **`Autocompletar`**: classe que gerencia o conjunto de termos e realiza a busca de preenchimento automático utilizando busca binária.
- **`main.cpp`**: arquivo principal que recebe parâmetros de linha de comando, carrega os dados e interage com o usuário no terminal.

---

## Funcionamento

1. O programa recebe dois parâmetros na execução:
   - Caminho para o arquivo de dataset contendo termos e pesos.
   - Número máximo `k` de resultados a serem exibidos.

2. O programa carrega o dataset e armazena os termos internamente.

3. O usuário digita um prefixo no terminal e pressiona Enter.

4. O sistema busca os termos que começam com o prefixo informado, usando busca binária.

5. Os termos encontrados são ordenados por peso em ordem decrescente.

6. São exibidos até `k` termos mais relevantes.

7. O processo se repete até que o usuário digite `sair`.

---

## Como Compilar e Executar

### Requisitos

- Compilador C++ compatível com C++17
- CMake (opcional, mas recomendado)
- Ambiente Linux (testado no Arch Linux com KDE Plasma. Windows também funciona, mas pode haver problemas com o comando make)

### Compilação (Exemplo com g++)
Para compilação do programa é necessário apenas digitar "make"

### Execução do Programa
```bash
make test
// ou caso queira mudar o dataset e o valor de nomes compátiveis encontrados
./bin/autocompletar datasets/(datasetNome).txt (quantidadeDeListados)
```


### Colaboradores

- [Artur Rochel](https://github.com/ArturRochel)
- [Jamykson Freitas](https://github.com/Jamykson)
