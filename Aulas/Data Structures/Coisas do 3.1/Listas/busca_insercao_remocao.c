//
//  main.c
//  recupera-arvore
//
//  Created by Luiz Araujo on 25/03/21.
//

#include <stdio.h>
#include <stdlib.h>

int pre[9] = {40,20,10,30,80,60,50,70,90};
int sim[9] = {10,20,30,40,50,60,70,80,90};

struct no {
    int rotulo;
    struct no *esq;
    struct no *dir;
};

struct no *arvore=NULL;

void recupera_bb (int *pre, int ip, int fp, struct no **raiz)
{
    // Criação da Raiz
    struct no *aux;
    int i;
    
    aux = malloc (sizeof(struct no));
    aux->dir=NULL;
    aux->esq=NULL;
    aux->rotulo=pre[ip];
    *raiz = aux;
    
    i = ip+1;
    while ((i <= fp) && (pre[i]<pre[ip]))
        i++;
    
    if (i != ip+1)
        recupera_bb (pre,ip+1,i-1,&((*raiz)->esq));
    if (i <= fp)
        recupera_bb (pre, i, fp, &((*raiz)->dir));
}



void recupera (int *pre, int *sim, int ip, int fp, int is, int fs, struct no **raiz)
{
    struct no *aux;
    int i;
    
    // Criação da Raiz
    
    aux = malloc (sizeof(struct no));
    aux->dir=NULL;
    aux->esq=NULL;
    aux->rotulo=pre[ip];
    *raiz = aux;
    
    // Busca da raiz na ordem simétrica
    
    i = is;
    
    while (i <= fs && sim[i] != aux->rotulo)
        i++;
    
    // i armazena a posição da raiz na ordem simétrica
    
    if ( i - is != 0 ) // subarvore esquerda da raiz não é vazia
        recupera (pre, sim, ip+1, ip+i-is, is, i-1, &(aux->esq));
    if ( i != fs )     // subarvire direita da raiz não é vazia
        recupera (pre, sim, ip+i-is+1, fp, i+1, fs, &(aux->dir));
}
    

void print_sim (struct no *r)
{
    if (r != NULL)
    {
        print_sim (r->esq);
        printf ("%d, ",r->rotulo);
        print_sim (r->dir);
    }
}

void print_pos (struct no *r)
{
    if (r != NULL)
    {
        print_pos (r->esq);
        print_pos (r->dir);
        printf ("%d, ",r->rotulo);
    }
}

struct no *busca (int chave, struct no *r, struct no **pai)
{
    if (r == NULL)
        return r;
    else if (r->rotulo == chave)
        return r;
    else
    {
        if (chave < r->rotulo) // a chave pode estar na direita
        {
            if (r->esq != NULL)
            {
                *pai = r;
                return busca (chave, r->esq, pai);
            }
            else
                return r;
        }
        else
        {
            if (r->dir != NULL)
            {
                *pai = r;
                return busca (chave, r->dir, pai);
            }
            else
                return r;
        }
    }
}

int inserir (int chave, struct no **r)
{
    struct no *aux,*pai=NULL, *newno;
    
    aux = busca (chave,*r,&pai);
    
    if (aux == NULL)
    {
        newno = malloc (sizeof(struct no));
        newno->rotulo = chave;
        newno->dir = NULL;
        newno->esq = NULL;
        *r = newno;
        return 1;
    }
    else
    {
        if (aux->rotulo == chave)
            return 0;
        else
        {
            newno = malloc (sizeof(struct no));
            newno->rotulo = chave;
            newno->dir = NULL;
            newno->esq = NULL;
            if (chave < aux->rotulo)
                aux->esq = newno;
            else
                aux->dir = newno;
            return 1;
        }
    }
}

struct no *remover (int chave, struct no **r, int subt)
{
    struct no *aux = NULL, *pai = NULL;
    
    aux = busca (chave, *r, &pai);
    
    if (aux == NULL)
        return NULL;
    else
    {
        if ((aux->rotulo == chave) || (subt == 1))
        {
            if ((aux->esq == NULL) && (aux->dir == NULL)) // Caso 1 - remoção de uma folha
            {
                if (pai == NULL) // estou removendo a raiz da árvore
                {
                    *r = NULL;
                    return aux;
                }
                else
                {
                    if (chave < pai->rotulo)
                    {
                        pai->esq = NULL;
                        return aux;
                    }
                    else
                    {
                        pai->dir = NULL;
                        return aux;
                    }
                }
            }
            else if ((aux->esq == NULL) || (aux->dir == NULL)) // Caso 2 - Nó interno com 1 filho
            {
                if (pai == NULL) // estou removendo a raiz
                {
                    if (aux->dir != NULL)
                    {
                        *r = aux->dir;
                    }
                    else
                    {
                        *r = aux->esq;
                    }
                    return aux;
                }
                else
                {
                    if (aux->dir != NULL)
                    {
                        if (pai->dir == aux)
                        {
                            pai->dir = aux->dir;
                            return aux;
                        }
                        else
                        {
                            pai->esq = aux->dir;
                            return aux;
                        }
                    }
                    else
                    {
                        if (pai->dir == aux)
                        {
                            pai->dir = aux->esq;
                            return aux;
                        }
                        else
                        {
                            pai->esq = aux->esq;
                            return aux;
                        }
                    }
                }
            }
            else
            {
                struct no *auxs=NULL;
                auxs = remover (chave, &(aux->esq), 1);
                
                if (pai == NULL)
                {
                    *r = auxs;
                    auxs->dir = aux->dir;
                    auxs->esq = aux->esq;
                    return aux;
                }
                else
                {
                    if (pai->dir == aux)
                    {
                        pai->dir = auxs;
                        auxs->dir = aux->dir;
                        auxs->esq = aux->esq;
                        return aux;
                    }
                    else
                    {
                        pai->esq = auxs;
                        auxs->dir = aux->dir;
                        auxs->esq = aux->esq;
                        return aux;
                    }
                }
            }
        }
        else
            return NULL;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    struct no *aux,*pai=NULL;
    int i=0;
    
    recupera_bb (pre, 0,8,&arvore);
    print_pos (arvore);
    printf("\n");
    aux = busca (50,arvore,&pai);
    printf (" aux = %d \n",aux->rotulo);
    printf (" pai = %d \n",pai->rotulo);
    aux = busca (75,arvore,&pai);
    printf (" aux = %d \n",aux->rotulo);
    printf (" pai = %d \n",pai->rotulo);
    printf("\n");
    
    aux = remover (30, &arvore, 0);
    printf ("aux = %d \n",aux->rotulo);
    free (aux);
    
    print_pos (arvore);
    
    aux = remover (20, &arvore, 0);
    printf ("aux = %d \n", aux->rotulo);
    free (aux);
    
    print_pos (arvore);
    
    aux = remover (80, &arvore, 0);
    printf ("aux = %d \n", aux->rotulo);
    free (aux);
    
    print_pos (arvore);
    
    return 0;
}
