#include <iostream>
#include "pecas.cpp"

string jogador1;

int verificarJogadores(int numJogadores)
{

    if (numJogadores < 2 || numJogadores > 4)
    {
        cout << "O número de jogadores deve ser dois ou quatro jogadores!" << endl;
        return 1;
    }
    if (numJogadores == 3)
    {
        cout << "Não é possível jogar com três jogadores!" << endl;
        return 1;
    }

    if (numJogadores == 2)
    {
        return numJogadores;
    }
    else
    {
        return numJogadores;
    }

    return 0;
}

Peca *montarMaoJogador(int numJogador, int numPecas, int numJogadores)
{

    Peca *pecas = criarPecas();

    Peca *maoJogador = new Peca[7];

    int start = (numJogador - 1) * 7;

    for (int i = 0; i < 7; i++)
    {
            maoJogador[i] = pecas[start + i];
            start++;
    }

    return maoJogador;
}

string nomearJogador(int jogador1)
{
    string nome;

    for (int i = 1; i < 5; i++)
    {
        if (jogador1 == i)
        {
            cout << "Digite o nome do jogador" << jogador1 << ": ";
            cin >> nome;
        }
    }

    return nome;
}