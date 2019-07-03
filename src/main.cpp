#include <iostream>
#include <fstream>
#include "arvore.h"

int main(int argc, char* argv[]) {

    Arvore arv = Arvore();
    std::ifstream arquivo("morse.txt");

    char caractere;
    std::string endereco;

    while (arquivo >> caractere >> endereco) {
        arv.inserir_em_endereco(caractere, endereco);
    }

    std::cout << arv.buscar_elemento("-.--")
              << arv.buscar_elemento("..-.")
              << arv.buscar_elemento("-.--") << std::endl;

    return 0;
}
