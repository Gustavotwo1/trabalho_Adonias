#include <iostream>

using namespace std;

// Estrutura do nó
struct No {
    int dado;
    No* prox;
};

// Inserir no final da lista
void inserir(No*& inicio, int valor) {
    No* novo = new No;
    novo->dado = valor;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
        return;
    }

    No* aux = inicio;

    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = novo;
}

// Busca Sequencial
bool buscaSequencial(No* inicio, int valor) {
    No* atual = inicio;

    while (atual != NULL) {
        if (atual->dado == valor)
            return true;

        atual = atual->prox;
    }

    return false;
}

// Encontrar nó do meio
No* meio(No* inicio, No* fim) {
    if (inicio == NULL)
        return NULL;

    No* lento = inicio;
    No* rapido = inicio->prox;

    while (rapido != fim) {
        rapido = rapido->prox;

        if (rapido != fim) {
            lento = lento->prox;
            rapido = rapido->prox;
        }
    }

    return lento;
}

// Busca Binária
bool buscaBinaria(No* inicio, int valor) {
    No* inicioAtual = inicio;
    No* fim = NULL;

    do {
        No* meioNo = meio(inicioAtual, fim);

        if (meioNo == NULL)
            return false;

        if (meioNo->dado == valor)
            return true;

        else if (meioNo->dado < valor)
            inicioAtual = meioNo->prox;

        else
            fim = meioNo;

    } while (fim == NULL || inicioAtual != fim);

    return false;
}

// Programa principal
int main() {

    No* lista = NULL;

    inserir(lista, 10);
    inserir(lista, 20);
    inserir(lista, 30);
    inserir(lista, 40);
    inserir(lista, 50);

    int valor;

    cout << "Digite um valor para buscar: ";
    cin >> valor;

    if (buscaSequencial(lista, valor))
        cout << "Busca Sequencial: Valor encontrado!" << endl;
    else
        cout << "Busca Sequencial: Valor nao encontrado!" << endl;

    if (buscaBinaria(lista, valor))
        cout << "Busca Binaria: Valor encontrado!" << endl;
    else
        cout << "Busca Binaria: Valor nao encontrado!" << endl;

    return 0;
}