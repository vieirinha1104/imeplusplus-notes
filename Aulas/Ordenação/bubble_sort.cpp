#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Tamanho da lista + Printar a lista de valores aleatorios
    int max;
    int aux=-1;
    printf("Digite o tamanho da lista:\n");
    scanf("%d",&max);
    int vector[100000];
    for(int i=0;i<max;i++){
        vector[i]=rand()%100;
        printf("%d ",vector[i]);
    }
    printf("\n");
    //Ordenar (Bubble Sort)
    for(int i=1;i<max;i++){
    for(int i=0;i<max-1;i++){
        if(vector[i]>vector[i+1]){
            aux=vector[i];
            vector[i]=vector[i+1];
            vector[i+1]=aux;
        }
    }
    }
    //Printar a lista ordenada
    for(int i=0;i<max;i++){
        printf("%d ",vector[i]);
    }
}
