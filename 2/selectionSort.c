#include <stdio.h>
#include <string.h>

typedef struct no{
	int valor;
	struct no* prox;

} No;

typedef struct lista{
	No* inicio;
	int tam;
} Lista;

Lista* lista_criar(){

    Lista *lista = malloc(sizeof(Lista));

    lista->inicio = NULL;
    lista->tam = 0;

    return lista;

}

void lista_pushInicio(Lista* lista, int num){
    
    No *novo = malloc(sizeof(No));

    if(novo){

        novo->valor = num;
        novo->prox = lista->inicio;

        lista->inicio = novo;

        lista->tam++;
    }
}

void lista_imprimir(Lista* lista){
    No* atual = lista->inicio;

    while(atual){
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void selectionSort(Lista* lista){
    No *i, *j, *min;

    for(i = lista->inicio; i != NULL; i = i->prox){
        min = i;

        // encontra o menor elemento com comparação
        for(j = i->prox; j != NULL; j = j->prox){
            if(j->valor < min->valor){
                min = j;
            }
        }
        // troca valores
        int temp = i->valor;
        i->valor = min->valor;
        min->valor = temp;
    }
}

int main(){
    Lista* lista = lista_criar();
    char opcao[2];
    int cont;

    while(1){

        printf("1 - Inserir\n");
        printf("2 - Ordenar (Selection Sort)\n");
        printf("0 - Sair\n");

        scanf("%s", opcao);

        if(strcmp(opcao, "1") == 0){
            printf("\nquantidade de numeros a inserir:\n");
            scanf("%d", &cont); // Limpa o buffer

            for(int i = 0; i < cont; i++){
                printf("\nDigite um numero:");

                int num;
                scanf("%d", &num);
                lista_pushInicio(lista, num);
            }
        }else if(strcmp(opcao, "2") == 0){
            printf("\nantes de ordenar:\n");
            lista_imprimir(lista);

            selectionSort(lista);
            printf("\ndepois de ordenar:\n");
            lista_imprimir(lista);


        }else if(strcmp(opcao, "0") == 0){
            break;

        }else{
            printf("Opcao invalida!\n");

        }
    }

    return 0;
}
