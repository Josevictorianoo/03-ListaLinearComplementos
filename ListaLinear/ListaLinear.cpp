#include <iostream>

using namespace std;

// Protótipos das funções
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
int posicaoElemento(int valor);

// Variáveis globais
const int MAX = 10;
int lista[MAX]{};
int nElementos = 0;

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // Somente no Windows
        cout << "Menu Lista Linear";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            inicializar();
            break;
        case 2:
            exibirQuantidadeElementos();
            break;
        case 3:
            exibirElementos();
            break;
        case 4:
            buscarElemento();
            break;
        case 5:
            inserirElemento();
            break;
        case 6:
            excluirElemento();
            break;
        case 7:
            return;
        default:
            cout << "Opcao invalida!\n";
            break;
        }

        system("pause"); // Somente no Windows
    }
}

void inicializar()
{
    nElementos = 0;
    cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos()
{
    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
    if (nElementos == 0)
    {
        cout << "A lista esta vazia \n";
    }
    else {
        cout << "Elementos: \n";
        for (int n = 0; n < nElementos; n++) {
            cout << lista[n] << endl;
        }
    }
}

void inserirElemento()
{
    int pos;
    int valor;
    if (nElementos < MAX) {
        cout << "Digite o elemento: ";
        cin >> valor;
        pos = posicaoElemento(valor);

        if (pos != -1)
        {
            cout << "Elemento ja esta na lista" << endl;
        }
        else
        {
            lista[nElementos] = valor;
            nElementos++;
            cout << "Elemento inserido com sucesso!\n";
        }
    }
    else {
        cout << "Lista cheia\n";
    }
}

void excluirElemento()
{
    // Verifica se a lista está vazia
    if (nElementos == 0) {
        cout << "A lista esta vazia \n";
        return;
    }

    int valor;
    cout << "Digite o elemento que deseja excluir: ";
    cin >> valor;

    // Busca o elemento usando a função auxiliar
    int pos = posicaoElemento(valor);

    if (pos != -1) {
        // Desloca os elementos à esquerda a partir da posição encontrada
        for (int i = pos; i < nElementos - 1; i++) {
            lista[i] = lista[i + 1];
        }

        // Decrementa o contador de elementos válidos
        nElementos--;
        cout << "Elemento excluido com sucesso!\n";
    }
    else {
        cout << "O elemento digitado nao foi encontrado" << endl;
    }
}

void buscarElemento()
{
    int valor;
    cout << "Digite o elemento que queira buscar: ";
    cin >> valor;

    int pos = posicaoElemento(valor);

    if (pos != -1) {
        cout << "O elemento foi encontrado na posicao " << pos << endl;
    }
    else
    {
        cout << "O elemento digitado nao foi encontrado" << endl;
    }
}

int posicaoElemento(int busca)
{
    // Retorna a primeira ocorrência do elemento na lista
    for (int i = 0; i < nElementos; i++) {
        if (busca == lista[i]) {
            return i;
        }
    }
    return -1; // Retorna -1 se não encontrar
}