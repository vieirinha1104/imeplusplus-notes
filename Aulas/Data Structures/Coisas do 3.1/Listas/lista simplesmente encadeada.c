//
//  main.c
//  lista-simp-enc-aula
//
//  Created by Luiz Araujo on 12/03/21.
//

#include <stdio.h>
#include <stdlib.h>


struct no {
    int chave;
    struct no *prox;
};

struct no *lista=NULL;

struct no *busca (int chave, struct no *lista, struct no **ant)
{
    struct no *aux=lista; // Inicializado com primeiro elemento
    *ant = NULL;          // Inicializado com NULL
    
    while ( (aux != NULL) && (aux->chave != chave))
    {
        *ant = aux;
        aux = aux->prox;
    }
    return aux;
}

int inserir (int chave, struct no **lista)
{
    struct no *aux=NULL;
    struct no *ant=NULL;
    
    aux = busca (chave, *lista, &ant);
    
    if (aux != NULL)
        return 0;
    else
    {
        aux = malloc (sizeof(struct no));
        aux->chave = chave;
        aux->prox = NULL;
        if (ant == NULL)
            *lista = aux;
        else
            ant->prox = aux;
        return 1;
    }
}

int remover (int chave, struct no **lista)
{
    struct no *aux = NULL;
    struct no *ant = NULL;
    
    aux = busca (chave, *lista, &ant);
    
    if (aux == NULL)
        return 0;
    else
    {
        if (ant == NULL) // aux é o primeiro da lista
        {
            *lista = aux->prox;
            free (aux);
            return 1;
        }
        else
        {
            ant->prox = aux->prox;
            free (aux);
            return 1;
        }
    }
}

void print_lista (struct no *lista)
{
    struct no *aux = lista;
    
    while (aux != NULL)
    {
        printf ("%d, ",aux->chave);
        aux = aux->prox;
    }
    printf ("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    inserir (10,&lista);
    print_lista (lista);
    inserir (30,&lista);
    print_lista (lista);
    inserir (20,&lista);
    print_lista (lista);
    inserir (5,&lista);
    print_lista (lista);
    
    remover (10,&lista);
    print_lista (lista);

    remover (20,&lista);
    print_lista (lista);


    return 0;
}
