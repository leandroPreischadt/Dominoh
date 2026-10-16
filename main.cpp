#include <iostream>
#include "pecas.cpp"
#include "tabuleiro.cpp"
#define TAM 25

using namespace std;

int main() {

    char** tabuleiro = criar_tabuleiro(TAM);
    mostrar_tabuleiro(tabuleiro, TAM);

    Peca *pecas = criarPecas();

    for (int i = 0; i < TAMPECAS - 1; i++)
    {
        cout << pecas[i].lado1 << "|" << pecas[i].lado2 << endl;
    }
    return 0;
}