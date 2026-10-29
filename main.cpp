#include <iostream>
#include "jogadores.cpp"
#include <stdlib.h>

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

    // Com quatro jogadores, todas as 28 peças já foram distribuídas.
    if (numJogadores == 4)
    {
        montante.quantidade = 0;
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

    jogador1.maoJogador = montarMaoJogador(1, jogador1);
    jogador2.maoJogador = montarMaoJogador(2, jogador2);
    jogador3.maoJogador = montarMaoJogador(3, jogador3);
    jogador4.maoJogador = montarMaoJogador(4, jogador4);

    Jogador &jogadorQueComeca = verificarQuemComeca(numJogadores, jogador1, jogador2, jogador3, jogador4);

    /*
    3- para 2 jogadores implementar montante e crir lógica de comprar peça
    4- exibir o tabuleiro na mesa com listas encadeadas
    5- criar logica de quem vai vencer (quem acaba com todas as peças primeiro)
    */

    Peca pecaEscolhida;
    Jogador *jogadorDaVez = &jogadorQueComeca;
    Jogador *vencedor = nullptr;

    while (true)
    {
        if (verificarEmpate(numJogadores, mesa, montante))
        {
            vencedor = verificarVencedorPorSoma(numJogadores);
            break;
        }

        if (montante.indiceAtual >= montante.quantidade &&
            !jogadorTemPecaJogavel(*jogadorDaVez, mesa))
        {
            jogadorDaVez = proximoJogador(jogadorDaVez, numJogadores);
            continue;
        }

        cout << "Jogador da vez: " <<jogadorDaVez->nome << endl;

        pecaEscolhida = escolherPecaMao(*jogadorDaVez, jogadorDaVez->quantidadeDePecas, mesa, montante);
        if (!montante.foiComprada)
        {
            InserirNaMesa(mesa, pecaEscolhida);
        }

        cout << "mesa:";
        exibirMesa(mesa);
        cout << endl;

        if (jogadorVencedor(jogadorDaVez))
        {
            vencedor = jogadorDaVez;
            break;
        }

        jogadorDaVez = proximoJogador(jogadorDaVez, numJogadores);
        
    }

    cout << endl;

    if (vencedor == nullptr)
    {
        cout << "A partida terminou empatada." << endl;
    }
    else
    {
        cout << "O vencedor é " << vencedor->nome << endl;
        cout << "Soma das peças: " << somarPecasJogador(*vencedor);
    }

    return 0;
}
