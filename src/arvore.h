#ifndef ARVORE_H
#define ARVORE_H

#include <string>

struct Node {
    char elemento;
    Node* esq;
    Node* dir;

    Node();
    ~Node();
};

class Arvore {
private:
public:
    Node* raiz;
    Arvore();
    ~Arvore() {}

    void inserir_em_endereco(char elemento, std::string endereco);
};


#endif
