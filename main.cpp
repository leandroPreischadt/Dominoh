#include <iostream>
#include "jogadores.cpp"

#define TAM 25
#define TAMPECAS 28
#define PECASPORMAO 7

using namespace std;

int main()
{
    int numJogadores;
    string jogador1;
    string jogador2;
    string jogador3;
    string jogador4;

    cout << "Quantos pessoas irão jogar?: ";
    cin >> numJogadores;
    int jogadoresVerificados = verificarJogadores(numJogadores);

    if (jogadoresVerificados == 1)
    {
        return 0;
    }

    if (jogadoresVerificados >= 2)
    {
        string jogador1 = nomearJogador(1);
        string jogador2 = nomearJogador(2);
        if (numJogadores == 4)
        {
            string jogador3 = nomearJogador(3);
            string jogador4 = nomearJogador(4);
        }
    }

    Peca *maoJogador1 = montarMaoJogador(1, TAMPECAS, numJogadores);
    Peca *maoJogador2 = montarMaoJogador(2, TAMPECAS, numJogadores);
    Peca *maoJogador3 = montarMaoJogador(3, TAMPECAS, numJogadores);
    Peca *maoJogador4 = montarMaoJogador(4, TAMPECAS, numJogadores);


    // while (true)
    // {
    //
    // }
    return 0;
}