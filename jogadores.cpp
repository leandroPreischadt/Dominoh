#include <iostream>
#include "pecas.cpp"
#include <string>

struct Jogador
{
    string nome;
    Peca *maoJogador;
    int pontos;
};

Jogador jogador1;
Jogador jogador2;
Jogador jogador3;
Jogador jogador4;

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

Peca *montarMaoJogador(int numJogador, int numPecas)
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

Jogador verificarQuemComeca(int numJogadores, Jogador jogador1, Jogador jogador2, Jogador jogador3, Jogador jogador4)
{

    Jogador jogadores[4] = {jogador1, jogador2, jogador3, jogador4};

    if (numJogadores >= 2)
    {
        if (numJogadores == 4)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < PECASPORMAO - 1; i++)
                {
                    if (jogadores[i].maoJogador[i].lado1 == 6 && jogadores[i].maoJogador[i].lado2 == 6)
                    {
                        return jogadores[i];
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < 2; j++)
            {
                for (int i = 0; i < PECASPORMAO - 1; i++)
                {
                    if (jogadores[j].maoJogador[i].lado1 + jogadores[j].maoJogador[i].lado2 > jogadores[j + 1].maoJogador[i].lado1 + jogadores[j + 1].maoJogador[1].lado2 || jogadores[j].maoJogador[i].lado1 + jogadores[j].maoJogador[i].lado2 > jogadores[j - j].maoJogador[i].lado1 + jogadores[j - j].maoJogador[i].lado1)
                    {
                        return jogadores[j];
                    }
                }
            }
        }
    }

    return jogador1;
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
