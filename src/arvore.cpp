#include "arvore.h"

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

Arvore::Arvore() {
    this->raiz = nullptr;
}

void Arvore::inserir_em_endereco(char elemento, std::string endereco) {
    if (this->raiz == nullptr)
        this->raiz = new Node();
    
    Node* atual = this->raiz;

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
