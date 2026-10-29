#include <iostream>
#include "jogadores.cpp"
#include <stdlib.h>

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

    jogador1.maoJogador = montarMaoJogador(1, TAMPECAS, jogador1);
    jogador2.maoJogador = montarMaoJogador(2, TAMPECAS, jogador2);
    jogador3.maoJogador = montarMaoJogador(3, TAMPECAS, jogador3);
    jogador4.maoJogador = montarMaoJogador(4, TAMPECAS, jogador4);

    Jogador &jogadorQueComeca = verificarQuemComeca(numJogadores, jogador1, jogador2, jogador3, jogador4);

    /*
    3- para 2 jogadores implementar montante e crir lógica de comprar peça
    4- exibir o tabuleiro na mesa com listas encadeadas
    5- criar logica de quem vai vencer (quem acaba com todas as peças primeiro)
    */

    Peca maoJogadorDaVez;
    Jogador *jogadorDaVez = &jogadorQueComeca;
    Mesa mesa = criarMesa();

    while (true)
    {

        cout << "Jogador da vez: " <<jogadorDaVez->nome << endl;

        maoJogadorDaVez = escolherPecaMao(*jogadorDaVez, jogadorDaVez->quantidadeDePecas);

        InserirNaMesa(mesa, maoJogadorDaVez);
        cout << "mesa:";
        exibirMesa(mesa);
        cout << endl;

        if (jogadorDaVez == &jogador1 && numJogadores >= 2)
        {
            jogadorDaVez = &jogador2;
        }
        else if (jogadorDaVez == &jogador2 && numJogadores==4)
        {
            jogadorDaVez = &jogador3;
        }
        else if (jogadorDaVez == &jogador3 && numJogadores ==4)
        {
            jogadorDaVez = &jogador4;
        } else {
            jogadorDaVez = &jogador1;
        }
        
    }
    return 0;
}
