#include <iostream>
#include "pecas.cpp"
#include <string>

struct Jogador
{
    string nome;
    Peca *maoJogador = nullptr;
    int quantidadeDePecas = 7;
    Peca pecaEscolhida;
};

Jogador jogador1;
Jogador jogador2;
Jogador jogador3;
Jogador jogador4;

Peca *pecas = nullptr;
Montante montante;
Mesa mesa = criarMesa();

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

    return numJogadores;
}

Peca *montarMaoJogador(int numJogador, Jogador &jogador)
{
    jogador.quantidadeDePecas = PECASPORMAO;

    // A mão pode crescer quando o jogador compra peças do montante.
    Peca *maoJogador = new Peca[TAMPECAS];
    int start = (numJogador - 1) * PECASPORMAO;

    for (int i = 0; i < PECASPORMAO; i++)
    {
        maoJogador[i] = pecas[start + i];
    }

    return maoJogador;
}

void liberarMaoJogador(Jogador &jogador)
{
    delete[] jogador.maoJogador;
    jogador.maoJogador = nullptr;
    jogador.quantidadeDePecas = 0;
}

void liberarRecursosPartida()
{
    liberarMaoJogador(jogador1);
    liberarMaoJogador(jogador2);
    liberarMaoJogador(jogador3);
    liberarMaoJogador(jogador4);

    liberarMesa(mesa);
    liberarMontante(montante);

    delete[] pecas;
    pecas = nullptr;
}

void reiniciarPartida(int numJogadores)
{

    liberarRecursosPartida();

    pecas = criarPecas();
    montante = criarMontante(pecas);
    mesa = criarMesa();

    if (numJogadores == 4)
    {
        montante.quantidade = 0;
    }

    jogador1.maoJogador = montarMaoJogador(1, jogador1);
    jogador2.maoJogador = montarMaoJogador(2, jogador2);
    jogador3.maoJogador = montarMaoJogador(3, jogador3);
    jogador4.maoJogador = montarMaoJogador(4, jogador4);
}

Jogador &verificarMaiorMao(Jogador &jogador1, Jogador &jogador2)
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

Jogador &verificarQuemComeca(int numJogadores, Jogador &jogador1, Jogador &jogador2, Jogador &jogador3, Jogador &jogador4)
{
    Jogador *jogadores[4] = {&jogador1, &jogador2, &jogador3, &jogador4};

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

    return verificarMaiorMao(jogador1, jogador2);
}

string nomearJogador(int numeroJogador)
{
    string nome;
    cout << "Digite o nome do jogador" << numeroJogador << ": ";
    cin >> nome;
    return nome;
}

Peca escolherPecaMao(Jogador &jogador, int &quantidadePecas, Mesa &mesa, Montante &montante)
{
    montante.foiComprada = false;

    while (true)
    {
        int escolha;

        for (int i = 0; i < quantidadePecas; i++)
        {
            cout << "(" << i + 1 << ") " << "[" << jogador.maoJogador[i].lado1 << "|" << jogador.maoJogador[i].lado2 << "]" << " ";
        }
        cout << endl;
        cout << "Escolha uma peça: ";
        cin >> escolha;

        if (escolha < 1 || escolha > quantidadePecas)
        {
            cout << "Escolha inválida!" << endl;
            continue;
        }

        int indice = escolha - 1;
        Peca pecaEscolhida = jogador.maoJogador[indice];

        if (!podeInserirNaMesa(pecaEscolhida, mesa))
        {
            Peca pecaComprada;

            if (comprarMontante(montante, pecaComprada))
            {
                jogador.quantidadeDePecas++;
                jogador.maoJogador[quantidadePecas - 1] = pecaComprada;
                cout << "Peça comprada do montante." << endl;
                return pecaComprada;
            }

            cout << "O montante está vazio. Escolha uma peça válida." << endl;
            continue;
        }

        for (int i = indice; i < quantidadePecas - 1; i++)
        {
            jogador.maoJogador[i] = jogador.maoJogador[i + 1];
        }

        jogador.quantidadeDePecas--;
        return pecaEscolhida;
    }
}

bool jogadorTemPecaJogavel(const Jogador &jogador, const Mesa &mesa)
{
    for (int i = 0; i < jogador.quantidadeDePecas; i++)
    {
        if (podeInserirNaMesa(jogador.maoJogador[i], mesa))
        {
            return true;
        }
    }

    return false;
}

bool verificarEmpate(int numJogadores, const Mesa &mesa, const Montante &montante)
{
    if (montante.indiceAtual < montante.quantidade)
    {
        return false;
    }

    Jogador *jogadores[4] = {&jogador1, &jogador2, &jogador3, &jogador4};
    int quantidadeJogadores = numJogadores == 4 ? 4 : 2;

    for (int i = 0; i < quantidadeJogadores; i++)
    {
        if (jogadorTemPecaJogavel(*jogadores[i], mesa))
        {
            return false;
        }
    }

    return true;
}

int somarPecasJogador(const Jogador &jogador)
{
    int soma = 0;

    for (int i = 0; i < jogador.quantidadeDePecas; i++)
    {
        soma += jogador.maoJogador[i].lado1 + jogador.maoJogador[i].lado2;
    }

    return soma;
}

Jogador *verificarVencedorPorSoma(int numJogadores)
{
    Jogador *jogadores[4] = {&jogador1, &jogador2, &jogador3, &jogador4};
    int quantidadeJogadores = numJogadores == 4 ? 4 : 2;
    int maiorSoma = 0;
    Jogador *vencedor = nullptr;
    bool houveEmpate = false;

    for (int i = 0; i < quantidadeJogadores; i++)
    {
        int somaAtual = somarPecasJogador(*jogadores[i]);

        if (somaAtual > maiorSoma)
        {
            maiorSoma = somaAtual;
            vencedor = jogadores[i];
            houveEmpate = false;
        }
        else if (somaAtual == maiorSoma)
        {
            houveEmpate = true;
        }
    }

    if (houveEmpate)
    {
        return nullptr;
    }

    return vencedor;
}

Jogador *proximoJogador(Jogador *jogadorDaVez, int numJogadores)
{
    if (jogadorDaVez == &jogador1)
    {
        return &jogador2;
    }

    if (jogadorDaVez == &jogador2 && numJogadores == 4)
    {
        return &jogador3;
    }

    if (jogadorDaVez == &jogador3 && numJogadores == 4)
    {
        return &jogador4;
    }

    return &jogador1;
}

bool jogadorVencedor(Jogador *jogador)
{
    return jogador->quantidadeDePecas == 0;
}
