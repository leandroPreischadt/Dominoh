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

struct Montante
{
    bool foiComprada = false;
    Peca *pecas = nullptr;
    int quantidade = 0;
    int indiceAtual = 0;
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

    shuffle(pecas, pecas + TAMPECAS, gerador);
    return pecas;
}

Montante criarMontante(Peca *pecas)
{
    Montante montante;
    montante.pecas = new Peca[MONTANTE];
    montante.quantidade = MONTANTE;

    for (int i = MONTANTE; i < TAMPECAS; i++)
    {
        montante.pecas[i - MONTANTE] = pecas[i];
    }

    return montante;
}

Mesa criarMesa()
{
    Mesa mesa;
    mesa.inicio = nullptr;
    return mesa;
}

void liberarMesa(Mesa &mesa)
{
    Peca *atual = mesa.inicio;

    while (atual != nullptr)
    {
        Peca *proxima = atual->prox;
        delete atual;
        atual = proxima;
    }

    mesa.inicio = nullptr;
}

void liberarMontante(Montante &montante)
{
    delete[] montante.pecas;
    montante.pecas = nullptr;
    montante.quantidade = 0;
    montante.indiceAtual = 0;
    montante.foiComprada = false;
}

Peca *criarPeca(Peca pecaDaMao)
{
    Peca *peca = new Peca;
    peca->lado1 = pecaDaMao.lado1;
    peca->lado2 = pecaDaMao.lado2;
    peca->prox = nullptr;
    return peca;
}

void inverterPeca(Peca &peca)
{
    Peca salvo;

    salvo.lado1 = peca.lado1;
    salvo.lado2 = peca.lado2;

    peca.lado1 = salvo.lado2;
    peca.lado2 = salvo.lado1;

}

void inseriInicio(Peca pecaDaMao, Mesa &mesa)
{
    Peca *peca = criarPeca(pecaDaMao);
    peca->prox = mesa.inicio;
    mesa.inicio = peca;
}

bool podeInserirNoInicio(const Peca &peca, const Mesa &mesa)
{
    if (mesa.inicio == nullptr)
    {
        return true;
    }

    return peca.lado1 == mesa.inicio->lado1 || peca.lado2 == mesa.inicio->lado1;
}

bool podeInserirNoFim(const Peca &peca, const Mesa &mesa)
{
    if (mesa.inicio == nullptr)
    {
        return true;
    }

    Peca *fim = mesa.inicio;
    while (fim->prox != nullptr)
    {
        fim = fim->prox;
    }

    return peca.lado1 == fim->lado2 || peca.lado2 == fim->lado2;
}

bool podeInserirNaMesa(const Peca &peca, const Mesa &mesa)
{
    return podeInserirNoInicio(peca, mesa) || podeInserirNoFim(peca, mesa);
}

bool InserirNaMesa(Mesa &mesa, Peca pecaDaMao)
{
    if (mesa.inicio == nullptr)
    {
        mesa.inicio = criarPeca(pecaDaMao);
        return true;
    }

    bool podeInicio = podeInserirNoInicio(pecaDaMao, mesa);
    bool podeFim = podeInserirNoFim(pecaDaMao, mesa);

    if (!podeInicio && !podeFim)
    {
        return false;
    }

    bool inserirNoInicio = podeInicio;

    if (podeInicio && podeFim)
    {
        int escolha;
        do
        {
            cout << "A peça pode ser inserida nos dois extremos." << endl;
            cout << "(1) Inserir no início  (2) Inserir no fim: ";
            cin >> escolha;

            if (escolha != 1 && escolha != 2)
            {
                cout << "Escolha inválida!" << endl;
            }
        } while (escolha != 1 && escolha != 2);

        inserirNoInicio = escolha == 1;
    }

    if (inserirNoInicio)
    {
        if (pecaDaMao.lado1 == mesa.inicio->lado1)
        {
            inverterPeca(pecaDaMao);
        }

        inseriInicio(pecaDaMao, mesa);
        return true;
    }

    Peca *atual = mesa.inicio;
    while (atual->prox != nullptr)
    {
        atual = atual->prox;
    }

    if (pecaDaMao.lado2 == atual->lado2)
    {
        inverterPeca(pecaDaMao);
    }

    atual->prox = criarPeca(pecaDaMao);
    return true;
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

bool comprarMontante(Montante &montante, Peca &pecaComprada)
{
    if (montante.indiceAtual >= montante.quantidade)
    {
        montante.foiComprada = false;
        return false;
    }

    pecaComprada = montante.pecas[montante.indiceAtual];
    montante.indiceAtual++;
    montante.foiComprada = true;
    return true;
}
