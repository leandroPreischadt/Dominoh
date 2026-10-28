#include <iostream>
#include "pecas.cpp"
#include <string>

struct Jogador
{
    string nome;
    Peca *maoJogador;
    int quantidadeDePecas;
    Peca pecaEscolhida;
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

Peca *pecas = criarPecas();

Peca *montarMaoJogador(int numJogador, int numPecas, Jogador &jogador)
{

    jogador.quantidadeDePecas = PECASPORMAO;

    Peca *maoJogador = new Peca[7];

    int start = (numJogador - 1) * 7;

    for (int i = 0; i < 7; i++)
    {
        maoJogador[i] = pecas[start + i];
    }

    return maoJogador;
}

Jogador& verificarMaiorMao(Jogador &jogador1, Jogador &jogador2)
{
    int maior1 = 0;
    int maior2 = 0;

    for (int i = 0; i < PECASPORMAO; i++)
    {
        if (jogador1.maoJogador[i].lado1 + jogador1.maoJogador[i].lado2 > maior1)
        {
            maior1 = jogador1.maoJogador[i].lado1 + jogador1.maoJogador[i].lado2;
        }

        if (jogador2.maoJogador[i].lado1 + jogador2.maoJogador[i].lado2 > maior2)
        {
            maior2 = jogador2.maoJogador[i].lado1 + jogador2.maoJogador[i].lado2;
        }
    }

    if (maior2 > maior1)
    {
        return jogador2;
    }

    return jogador1;
}

Jogador& verificarQuemComeca(int numJogadores, Jogador &jogador1, Jogador &jogador2, Jogador &jogador3, Jogador &jogador4)
{

    Jogador *jogadores[4] = {&jogador1, &jogador2, &jogador3, &jogador4};

    if (numJogadores >= 2)
    {
        if (numJogadores == 4)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < PECASPORMAO; i++)
                {
                    if (jogadores[j]->maoJogador[i].lado1 == 6 && jogadores[j]->maoJogador[i].lado2 == 6)
                    {
                        return *jogadores[j];
                    }
                }
            }
        }
        else
        {
            return verificarMaiorMao(jogador1, jogador2);
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

Peca escolherPecaMao(Jogador &jogador, int &quantidadePecas)
{
    while (true)
    {
        int escolha;

        for (int i = 0; i < quantidadePecas; i++)
        {
            cout << "(" << i + 1 << ") " << jogador.maoJogador[i].lado1 << "|" << jogador.maoJogador[i].lado2 << " ";
        }
        cout << endl;
        cout << "Escolha uma peça: ";
        cin >> escolha;

        if (escolha >= 1 && escolha <= quantidadePecas)
        {
            int indice = escolha - 1;
            Peca pecaEscolhida = jogador.maoJogador[indice];

            for (int i = indice; i < quantidadePecas - 1; i++)
            {
                jogador.maoJogador[i] = jogador.maoJogador[i + 1];
            }

            jogador.quantidadeDePecas--;

            return pecaEscolhida;
        }

        cout << "Escolha inválida!" << endl;
    }
}

Jogador& VezJogador(Jogador &jogadorQueComeca, Jogador &jogador)
{
    if (jogadorQueComeca.nome == jogador.nome)
    {
        cout << "jogador: " << jogadorQueComeca.nome << endl;
        return jogadorQueComeca;
    }
    cout << "Jogador: " << jogador.nome << endl;
    return jogador;
}