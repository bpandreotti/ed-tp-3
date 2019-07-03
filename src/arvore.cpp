#include "arvore.h"
#include <string>
#include <iostream>

Node::Node() {
    this->elemento = '!'; // Nodes vazios denotados com '!'
    this->esq = nullptr;
    this->dir = nullptr;
}

Node::~Node() {
    if (this->esq != nullptr)
        delete this->esq;
    if (this->dir != nullptr)
        delete this->dir;
}

// Esse método imprime o elemento e endereço do Node e se chama recursivamente nos filhos do Node.
void Node::imprimir_pre_ordem(std::string acumulador) {
    if (this->elemento != '!')
        std::cout << this->elemento << " " << acumulador << std::endl;
    
    // O acumulador deve sempre ser o endereço do Node no qual o método está sendo chamado, então
    // acrescentamos um ponto para o filho da esquerda e um traço para o da direita.
    if (this->esq != nullptr)
        this->esq->imprimir_pre_ordem(acumulador + ".");
    if (this->dir != nullptr)
        this->dir->imprimir_pre_ordem(acumulador + "-");
}

Arvore::Arvore() {
    this->raiz = nullptr;
}

Arvore::~Arvore() {
     // O destrutor de Node garante que, ao chamar o destrutor da raiz, toda a árvore será deletada
     // recursivamente.
    if (this->raiz != nullptr)
        delete this->raiz;
}

void Arvore::inserir_em_endereco(char elemento, std::string endereco) {
    if (this->raiz == nullptr)
        this->raiz = new Node();

    Node* atual = this->raiz;

    // Percorre a árvore de acordo com cada caractere do endereço, criando Nodes vazios pelo
    // caminho se necessário.
    for (char& c : endereco) {
        if (c == '.') {
            if (atual->esq == nullptr)
                atual->esq = new Node();
            atual = atual->esq;
        } else if (c == '-') {
            if (atual->dir == nullptr)
                atual->dir = new Node();
            atual = atual->dir;
        }
    }

    atual->elemento = elemento;
}

char Arvore::buscar_elemento(std::string endereco) {
    Node* atual = this->raiz;

    for (char& c : endereco) {
        if (c == '.')
            atual = atual->esq;
        else if (c == '-')
            atual = atual->dir;

        if (atual == nullptr)
            return '!'; // Indica que o endereço não corresponde a nenhum elemento na árvore.
    }

    return atual->elemento;
}

void Arvore::imprimir_arvore() {
    this->raiz->imprimir_pre_ordem("");
}
