#include <iostream>
using namespace std;

char **criar_tabuleiro(int TAM) {
    char** tabuleiro = new char*[TAM];
    for (int i = 0; i < TAM; i++)
    {
        tabuleiro[i] = new char[TAM];
    }

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            tabuleiro[i][j] = '.';
        }
    }

    return tabuleiro;
}

void mostrar_tabuleiro(char **matriz, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}