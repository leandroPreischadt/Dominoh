#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

random_device rd;
mt19937 gerador(rd());

#define TAMPECAS 28
#define MONTANTE 14
#define PECASPORMAO 7

struct Peca
{
    int lado1;
    int lado2;
    Peca *prox = nullptr;
};

struct Mesa
{
    Peca *inicio;
};

Peca *criarPecas()
{

    int pecaIndex = 0;

    Peca *pecas = new Peca[TAMPECAS];

    for (int i = 0; i < 7; i++)
    {
        for (int j = i; j < 7; j++)
        {
            Peca p;
            p.lado1 = i;
            p.lado2 = j;
            pecas[pecaIndex] = p;
            pecaIndex++;
        }
    }

    shuffle(pecas, pecas + 28, gerador);

    return pecas;
}

Peca *criarMontante(Peca *pecas)
{
    Peca *montante = new Peca[MONTANTE];
    
    for (int i = MONTANTE; i < TAMPECAS; i++)
    {
        montante[MONTANTE - 1] = pecas[i];
    }

    return montante;
}

Mesa criarMesa()
{
    Mesa mesa;
    mesa.inicio = nullptr;
    return mesa;
}

Peca *criarPeca(Peca maoJogadorDaVez){
    Peca *peca = new Peca;
    peca->lado1 = maoJogadorDaVez.lado1;
    peca->lado2 = maoJogadorDaVez.lado2;
    peca->prox = nullptr;
    return peca;
}

void inseriInicio(Peca maoJogadorDaVez, Mesa &mesa)
{
    Peca *peca = criarPeca(maoJogadorDaVez);

    if(peca->lado2 == mesa.inicio->lado1)
    {
        peca->prox = mesa.inicio;
        mesa.inicio = peca;
    }
}

void InserirNaMesa(Mesa &mesa, Peca maoJogadorDaVez)
{

    Peca *peca = criarPeca(maoJogadorDaVez);

    if (mesa.inicio == nullptr)
    {
        mesa.inicio = peca;
        return;
    }

    else if (peca->lado2 == mesa.inicio->lado1)
    {
        inseriInicio(*peca, mesa);
        return;
    }else
    {
        Peca *atual = mesa.inicio;
        while (atual->prox != nullptr)
        {
            atual = atual->prox;
        }

        if (atual->lado2 == peca->lado1)
        {
            atual->prox = peca;
        }
        else
        {
            return;
        }
    }
}

void exibirMesa(const Mesa &mesa)
{
    Peca *atual = mesa.inicio;

    while (atual != nullptr)
    {
        cout << "[" << atual->lado1 << "|" << atual->lado2 << "]" << " ";
        atual = atual->prox;
    }
    
}