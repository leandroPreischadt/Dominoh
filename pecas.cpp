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
    Peca *prox;
};

struct Fileira {
    Peca *inicio;
    int tamanho;
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
    int start = MONTANTE;

    for (int i = start; i < TAMPECAS; i++)
    {
        montante[i] = pecas[i];
    }

    return montante;
}

Fileira conectarPeca()
{
    Fileira f;
    f.inicio = nullptr;
    f.tamanho = 0;
    return f;
}

Fileira inseriInicio(Peca &maoJogador, Fileira &f) {
    Peca *nova = nullptr;
    nova = &maoJogador;
}