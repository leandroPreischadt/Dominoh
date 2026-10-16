#include <iostream>
using namespace std;
#define TAMPECAS 28

struct Peca
{
    int lado1;
    int lado2;
};

Peca *criarPecas()
{
    int pecaIndex = 0;

    Peca *pecas = new Peca[TAMPECAS];

    for (int i=0; i <7; i++) {
        for(int j=i; j<7; j++) {
            Peca p;
            p.lado1 = i;
            p.lado2 = j;
            pecas[pecaIndex] = p;
            pecaIndex++;
        }
    }
    return pecas;
}
