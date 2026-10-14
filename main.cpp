#include <iostream>
#include "pecas.cpp"
#include "tabuleiro.cpp"
#define TAM 25

using namespace std;

int main() {

    char** tabuleiro = criar_tabuleiro(TAM);
    mostrar_tabuleiro(tabuleiro, TAM);

    return 0;
}