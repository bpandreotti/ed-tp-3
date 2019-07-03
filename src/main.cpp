#include <iostream>
#include <fstream>
#include <sstream>
#include "arvore.h"

int main(int argc, char* argv[]) {

    Arvore arvore = Arvore();
    std::ifstream arquivo("morse.txt");

    char caractere;
    std::string endereco;
    // Lê um char e uma string do arquivo de entrada. O primeiro operador `>>` lê um char do
    // arquivo, e o segundo lê uma string até o final da linha. Para cada par (`caractere`,
    // `endereco`), insere o caractere na árvore com o devido endereço.
    while (arquivo >> caractere >> endereco) {
        arvore.inserir_em_endereco(caractere, endereco);
    }

    std::string linha;
    // Lê cada linha da entrada padrão sequencialmente.
    while (std::getline(std::cin, linha)) {
        std::stringstream sstream(linha);
        std::string s;

        // Para cada linha da entrada, divide ela em tokens separados por espaços. Como definido
        // pela especificação, esses tokens serão: ou a representação em morse de uma letra, e.g.
        // "..-.", ou o separador de palavras, "/". No primeiro caso, decodificamos a letra
        // buscando-a na árvore. No segundo caso, imprimimos " ".
        while (std::getline(sstream, s, ' ')) {
            if (s == "/")
                std::cout << " ";
            else
                std::cout << arvore.buscar_elemento(s);
        }

        std::cout << std::endl;
    }

    return 0;
}
