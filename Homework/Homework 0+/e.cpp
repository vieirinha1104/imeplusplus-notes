#include <bits/stdc++.h>

using namespace std;
int main(){
  //entradas
   int vector [1000];
   int n,k;
   cin >> n >> k;
   int aux=0;
   int sum=0;
   while(aux!=n){
        cin >> vector[aux];
        aux++;
   }
   //Ordenar (Bubble Sort)
    for(int i=1;i<aux;i++){
    for(int i=0;i<aux-1;i++){
        if(vector[i]>vector[i+1]){
            int a=vector[i];
            vector[i]=vector[i+1];
            vector[i+1]=a;
        }
    }
    }
    //saida
    for(int i=0;i<k;i++){
        sum=sum+vector[i];
    }
    cout << sum << "\n";
 
}

