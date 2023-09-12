#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    int aux;
    int vector[100];
   //entradas:
    
    cin >> n;
   
    for(int i=0;i<n;i++){
        cin >> vector[i];
    }
    //menor valor da lista:
    int min=vector[0];
    for(int i=1;i<n;i++){
        if(vector[i]<min){
            min=vector[i];
        }
    }

    //Ordenar (Bubble Sort)
    for(int i=1;i<n;i++){
    for(int i=0;i<n-1;i++){
        if(vector[i]>vector[i+1]){
            aux=vector[i];
            vector[i]=vector[i+1];
            vector[i+1]=aux;
        }
    }
    }

    //saida:
    
    if(vector[n-1]==min){
        cout << "NO" <<"\n";
        return 0;
    }

    for(int i=0;i<n;i++){
        if(vector[i]>min){
            cout << vector[i] << "\n";
            return 0;
        }
    
    }
    



}