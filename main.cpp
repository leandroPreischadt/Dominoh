#include <iostream>
#include "jogadores.cpp"

#define TAMPECAS 28


using namespace std;

int main()
{
    int numJogadores;

    cout << "Quantos pessoas irão jogar?: ";
    cin >> numJogadores;
    int jogadoresVerificados = verificarJogadores(numJogadores);

    if (jogadoresVerificados == 1)
    {
        return 0;
    }

    if (jogadoresVerificados >= 2)
    {
        jogador1.nome = nomearJogador(1);
        jogador2.nome = nomearJogador(2);
        if (numJogadores == 4)
        {
            jogador3.nome = nomearJogador(3);
            jogador4.nome = nomearJogador(4);
        }
    }

    jogador1.maoJogador = montarMaoJogador(1, TAMPECAS);
    jogador2.maoJogador = montarMaoJogador(2, TAMPECAS);
    jogador3.maoJogador = montarMaoJogador(3, TAMPECAS);
    jogador4.maoJogador = montarMaoJogador(4, TAMPECAS);

    Jogador jogadorQueComeca = verificarQuemComeca(numJogadores, jogador1, jogador2, jogador3, jogador4);

    cout << "O jogador que começa é o " << jogadorQueComeca.nome << endl;
    
    Peca maoJogadorQueComeca = escolherPecaMao(jogadorQueComeca);
    cout << "Peça escolhida: " << maoJogadorQueComeca.lado1 << "|" << maoJogadorQueComeca.lado2 << endl;

    // while (true)
    // {
    //
    // }
    return 0;
}