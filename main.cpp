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

    jogador1.maoJogador = montarMaoJogador(1, TAMPECAS, jogador1);
    jogador2.maoJogador = montarMaoJogador(2, TAMPECAS, jogador2);
    jogador3.maoJogador = montarMaoJogador(3, TAMPECAS, jogador3);
    jogador4.maoJogador = montarMaoJogador(4, TAMPECAS, jogador4);

    Jogador jogadorQueComeca = verificarQuemComeca(numJogadores, jogador1, jogador2, jogador3, jogador4);

    cout << "O jogador que começa é o " << jogadorQueComeca.nome << endl;
    /*
    1- implementar quando são 2 jogadores ou 4
    2- algortirmo para os próximos jogadores jogarem suas peças
    3- para 2 jogadores implementar montante e crir lógica de comprar peça
    4- exibir o tabuleiro na mesa com listas encadeadas
    5- criar logica de quem vai vencer (quem acaba com todas as peças primeiro)
    */

    Peca maoJogadorQueComeca;

    while (true)
    {
    
        if (numJogadores >= 2)
        {
            //para os dois jogadores

            // maoJogadorQueComeca = escolherPecaMao(jogadorQueComeca, jogadorQueComeca.quantidadeDePecas);

            if (numJogadores ==4)
            {
                // Para 4 jogadores, colocar as mãons dos outros dois jogadores que faltam
            }
            
        }
        

    }
    return 0;
}