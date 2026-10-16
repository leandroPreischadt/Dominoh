#include <iostream>
using namespace std;
#define TAMPECAS 28

struct Peca
{
    int lado1;
    int lado2;
};

Peca *criarPecas(int tamanhoVetor)
{

    Peca *pecas = new Peca[28];

    int adicional = 0;
    for (int i = 0; i < tamanhoVetor - 1; i++)
    {
        for (int k = 0; k < 6; k++)
        {
            if (i < 6)
            {
                Peca p;
                p.lado1 = adicional;
                p.lado2 = k;
                pecas[i] = p;
            }
            if (i < 12)
            {
                Peca p;
                p.lado1 = adicional + 1;
                p.lado2 = k;
                pecas[i] = p;
            }

            if (i < 17)
            {
                /* code */
            }
            
            
        }
    }
    return pecas;
}
