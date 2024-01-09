//
//  main.c
//  arv-comp
//
//  Created by Luiz Araujo on 22/05/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N = 0;

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};


struct no *raiz = NULL;

void inserir (struct no **r, int chave)
{
    struct no *aux;
    if (*r == NULL)
    {
        aux = malloc (sizeof(struct no));
        aux->chave = chave;
        aux->dir = NULL;
        aux->esq = NULL;
        *r = aux;
        N++;
    }
    else if ((*r)->chave < chave)
        inserir (&((*r)->dir),chave);
    else
        inserir (&((*r)->esq),chave);
}

void print_pre (struct no *r)
{
    if (r != NULL)
    {
        printf ("%d, ",r->chave);
        print_pre (r->esq);
        print_pre (r->dir);
    }
}

void rdir (struct no **p)
{
    struct no *auxu, *auxv;
    auxv = *p;
    auxu = auxv->esq;
    *p = auxu;
    auxv->esq = auxu->dir;
    auxu->dir = auxv;
}

void resq (struct no **p)
{
    struct no *auxu, *auxv;
    auxu = *p;
    auxv = (*p)->dir;
    auxu->dir = auxv->esq;
    auxv->esq = auxu;
    *p = auxv;
}
//Passo 2 transforma uma arvore zig zag toda para direita em uma arvore binaria completa(otima)
void passo2 (struct no **r)
{
    int L = 0;
    int U = 0;
    int ex = 0;
    int i;
    int nrNosUltNiv =0;
    int nrRot =0;
    struct no **rrot=r;
    
    ex = (int) log2(N);
    L = pow(2,ex) - 1;
    U = N - L;
    for (i=1; i <= U; i++)
    {
        if (i == 1)
        {
            resq (r);
            rrot = &((*r)->dir);
        }
        else
        {
            resq (rrot);
            rrot = &((*rrot)->dir);
        }
    }
    nrNosUltNiv = (int) pow (2,(int)log2(N)-1);
    nrRot = nrNosUltNiv - 1;
    while (nrRot != 0)
    {
        rrot = r;
        for (i=1; i <= nrRot; i++)
        {
            if (i == 1)
            {
                resq (r);
                rrot = &((*r)->dir);
            }
            else
            {
                resq (rrot);
                rrot = &((*rrot)->dir);
            }
        }
        nrRot = nrRot/2;
    }
}
//Passo 1 transforma uma arvore binaria qualquer em uma arvore zig zag toda para direita
void passo1 (struct no **r)
{
    if (*r != NULL)
    {
        if ((*r)->esq != NULL)
            rdir (r);
        if ((*r)->esq != NULL)
            passo1 (r);
        else
            passo1 (&((*r)->dir));
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    for (i=1; i<=50000; i++)
        inserir (&raiz,i);
    
    passo1(&raiz);
    
    passo2(&raiz);
    print_pre(raiz);
    return 0;
}