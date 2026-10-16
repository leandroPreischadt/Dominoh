#include <iostream>
#include "pecas.cpp"

string jogador1;

bool verificarJogadores(int numJogadores) {

    if (numJogadores < 2 || numJogadores > 4)
    {
        cout <<"O número de jogadores deve ser dois ou quatro jogadores!" << endl;
        return true;
    } 
    else if (numJogadores==3)
    {
        cout << "Não é possível jogar com três jogadores!" << endl;
        return true;
    }
    return false;
}

Peca *montarMaoJogador(int quantidadePecas) {
    Peca *pecas = criarPecas();

    Peca *maoJogador = new Peca[7];

    for (int i = 0; i < 7; i++)
    {
        maoJogador[i] = pecas[i];
    }
    
    return maoJogador;
}