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

Peca *pecas = criarPecas();


Peca *montarMaoJogador(int numJogador,int numPecas)
{
    Peca *maoJogador = new Peca[7];
    int start=0;

    if (numJogador==2)
    {
        start = numPecas - (numPecas-7);
    }
    else if (numJogador==3)
    {
        start= numPecas - (numPecas-14);
    }
    else if (numJogador==4)
    {
        start= numPecas - (numPecas - 21);
    }
    
    
    for (int i = 0; i < 7; i++)
    {
        maoJogador[i] = pecas[start];
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