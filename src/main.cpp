#include <iostream>
#include <fstream>
#include <sstream>
#include "arvore.h"

int main(int argc, char* argv[]) {

    Arvore arv = Arvore();
    std::ifstream arquivo("morse.txt");

    char caractere;
    std::string endereco;

    while (arquivo >> caractere >> endereco) {
        arv.inserir_em_endereco(caractere, endereco);
    }

    std::string linha;
    while (std::getline(std::cin, linha)) {
        std::string s;
        std::stringstream sstream(linha);
        while (std::getline(sstream, s, ' ')) {
            if (s == "/")
                std::cout << " ";
            else {
                std::cout << arv.buscar_elemento(s);
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
