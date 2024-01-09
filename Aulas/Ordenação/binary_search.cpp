#include <bits/stdc++.h>

using namespace std;

void busca_binaria(int *v,int inicio,int fim, int valor){
    int mid= (inicio+fim+1)/2;
    if(valor<v[inicio]){
        cout<<"O numero desejado nao esta na lista\n";
        return;
    }
    if(valor>v[fim]){
        cout<< "O numero desejado nao esta na lista\n";
        return;
    }
    else if(v[mid-1]==valor){
        cout<<mid-1<<"\n";
        return;
    }
    else if(v[mid-1]>valor){
        busca_binaria(v,inicio,mid-1,valor);
    }
    else{
        busca_binaria(v,mid,fim,valor);
    }

}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int vector[8]={12,43,50,77,123,500,700,830};
    busca_binaria(vector,0,7,55);    
}
//Caso o array esteja sortido:
//se for necessario procurar um elemento no array apenas uma vez, basta fazer uma busca linear -> complexidade: n
//se for necessario fazer varias buscas em um array, ordenar primeiro e depois fazer a busca binaria
