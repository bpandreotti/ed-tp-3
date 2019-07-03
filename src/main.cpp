#include <iostream>

#include "arvore.h"

int main(int argc, char* argv[]) {

    Arvore arv = Arvore();

    arv.inserir_em_endereco('A', "..-.");
    arv.inserir_em_endereco('B', "-...");
    arv.inserir_em_endereco('C', "-.-.");

    return 0;
}
