#ifndef ARVORE_H
#define ARVORE_H

#include <string>

// Um node na árvore binária, armazenando um `char`. Caso este seja "!", o Node não foi
// inicializado, e está vazio.
struct Node {
    char elemento;
    Node* esq;
    Node* dir;

    Node();
    ~Node();
};

// Uma árvore binária de `char`s. Elementos podem ser inseridos e buscados com um endereço definido
// por uma string de pontos e traços, onde um ponto indica ir para esquerda, e um traço indica ir
// para a direita. O enderço da raiz é uma string vazia.
class Arvore {
private:
    Node* raiz;
public:
    Arvore();
    ~Arvore();

    // Insere um elemento na árvore com um dado endereço. Quando necessário, cria Nodes vazios no
    // caminho até o endereço.
    void inserir_em_endereco(char elemento, std::string endereco);

    // Busca um elemento em certo endereço na árvore. Se o Node correspondente estiver vazio ou
    // não existir, retorna "!".
    char buscar_elemento(std::string endereco);
};

#endif
