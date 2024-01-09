//
//  main.cpp
//  lista-estatica
//
//  Created by Luiz Araujo on 26/02/21.
//

#include <iostream>
#define tam_vet 10

int lista[tam_vet]={20, 10, 8, 6, 18, 22, 27, 4, 18, 1};
int tam = 0; // Lista criada vazia

int busca (int chave) // O(n)
{
    int i = 0;
    while ((i < tam) && (lista[i] != chave))
        i++;
    return i;
}

int inserir (int chave) // O(n)
{
    int aux = 0;
    
    aux = busca (chave); // O(n)
    
    if ((aux == tam) && (aux < tam_vet))
    {
        lista[aux]=chave;
        tam++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int remover (int chave) // O(n)
{   int pos, i;
    
    pos = busca (chave);
    
    if (pos < tam)
    {
        for ( i=pos; i < tam-1; i++)
            lista[i]=lista[i+1];
        tam --;
        return 1;
    }
    else
        return 0;
}


int main(int argc, const char * argv[]) {
    int x =0;
    
    x = busca (50);
    
    x = inserir (50);
    x = inserir (20);
    x = inserir (30);
    x = inserir (60);
    
    x = remover (60);
    
    return 0;
}
