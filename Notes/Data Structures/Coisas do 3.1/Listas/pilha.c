//
//  main.c
//  pilha-aula
//
//  Created by Luiz Araujo on 11/03/21.
//

#include <stdio.h>
#define TAM_PILHA 10


int pilha[TAM_PILHA];
int topo=-1; // pilha está vazia.

int push (int elm)
{
    if (topo == TAM_PILHA - 1)
    {
        return 0; // Pilha cheia
    }
    else
    {
        topo++;
        pilha[topo]=elm;
        return 1;
    }
}

int pop ()
{
    if (topo == -1)
    {
        return 0;
    }
    else
    {
        topo--;
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    push (10);
    push (20);
    push(10);
    pop();
    push (30);
    return 0;
}
