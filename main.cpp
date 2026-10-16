#include <iostream>
#include "tabuleiro.cpp"
#include "jogadores.cpp"

#define TAM 25
#define QNTDPECAS 28
#define PECASPORMAO 7

using namespace std;

int main() {

    int numJogadores;
    Peca *maoJogador1 = montarMaoJogador(QNTDPECAS);

    char** tabuleiro = criar_tabuleiro(TAM);
    mostrar_tabuleiro(tabuleiro, TAM);
    
    cout << "Quantos pessoas irão jogar?: ";
    cin >> numJogadores;

    bool jogadoresVerificados = verificarJogadores(numJogadores);

    if (jogadoresVerificados)
    {
        return 0;
    }

    return 0;
}