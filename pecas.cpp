#include <iostream>
using namespace std;
#define TAMPECAS 28

int **cirarPecas()
{

    int lado1 = 0;
    int lado2 = 0;

    int **pecas = new int *[28];
    for (int i = 0; i < 1; i++)
    {
        pecas[i] = new int[1];
    }

    for (int i = 0; i < 28; i++)
    {

        for (int j = 0; j < 1; j++)
        {
            
            for (int k = 0; k < 6; k++)
            {
                pecas[i][j] = k;

                if (i<6 && (j==1))
                {
                    pecas[i][j]= 0;
                }

                if (i < 12)
                {
                    pecas[i][j] = k + 1;
                    if (j==1)
                    {
                        pecas[i][j] = 1;
                    }
                }

                if (i<17)
                {
                    pecas[i][j] = k + 2;
                    if (j==1)
                    {
                        pecas[i][j] = 2;
                    }
                    
                }

                if (i<21)
                {
                    pecas[i][j] = k + 3;

                    if (j==1)
                    {
                        pecas[i][j] = 3;
                    }
                    
                }

                if (i<24)
                {
                    pecas[i][j] = k + 3;

                    if (j==1)
                    {
                        pecas[i][j] = 4;
                    }
                    
                }
            }
        }
    }

    return pecas;
}

// if (i < 6)
//             {
//                 pecas[i][j] = lado1 + lado2;
//                 lado2++;

//                 if (j==1)
//                 {
//                     pecas[i][1] = 0;
//                 }
                
//                 if (i==6)
//                 {
//                     lado2 = 0;
//                     lado1 = 1;
//                 }
                

//             }

//             if (i < 12)
//             {
//                 pecas[i][j] = lado1 + lado2;
//                 lado2++;

//                 if (j==1)
//                 {
//                     pecas[i][1] = 1;
//                 }
//             }