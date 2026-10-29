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

    char jogarNovamente = 'n';

    do
    {
        reiniciarPartida(numJogadores);

        Jogador &jogadorQueComeca = verificarQuemComeca(numJogadores, jogador1, jogador2, jogador3, jogador4);
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

            //lógica pra ver se o jogador tem peça jogavel, se não pula vez
            if (montante.indiceAtual >= montante.quantidade && !jogadorTemPecaJogavel(*jogadorDaVez, mesa))
            {
                jogadorDaVez = proximoJogador(jogadorDaVez, numJogadores);
                continue;
            }

            cout << "Jogador da vez: " << jogadorDaVez->nome << endl;

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
            cout << "Soma das peças: " << somarPecasJogador(*vencedor) << endl;
        }

        cout << "Deseja jogar novamente com os mesmos jogadores? (s/n): ";
        cin >> jogarNovamente;
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    liberarRecursosPartida();

    return 0;
}
