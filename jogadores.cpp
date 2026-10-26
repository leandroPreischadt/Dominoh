#include <iostream>
#include "pecas.cpp"
#include <string>

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

/*
Peca *verificarQuemComeca(int numJogadores, Peca *maoJgador1, Peca *maoJgador2, Peca *maoJgador3, Peca *maoJgador4)
{

   Peca *jogadores[4] = {maoJgador1, maoJgador2, maoJgador3, maoJgador4};
    

   for (int i = 0; i < TAMPECAS - 1; i++)
   {

   }
   
}
*/

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

struct Jogador {
    string nome;
    Peca *maoJogador;
    int pontos;
};