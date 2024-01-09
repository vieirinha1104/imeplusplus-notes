#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *v,int tam){
    for(int i=1;i<tam;i++){
        int aux=v[i];
        int j=i-1;
        while(j>=0 && v[j]>aux){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

int main(){
     int tam;
    printf("Digite o tamanho do vetor de notas\n");
    scanf("%d",&tam);
    int *vector=(int*)malloc(tam*sizeof(int));
    printf("Digite o vetor de notas\n");
        for(int i = 0;i<tam;i++) {
        scanf("%d", &vector[i]);
    }
    insertion_sort(vector,tam);
    for(int i=0;i<tam;i++){
    printf("%d ",vector[i]);
    }
}