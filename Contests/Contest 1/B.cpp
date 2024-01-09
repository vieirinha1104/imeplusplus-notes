#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    long long x;
    long long vector[200000];
    int y=-1;
    cin >> n;
    cin >> x;
    for(int i=0;i<n;i++){
        cin >> vector[i];
    }
    long long aux[200000];
    for(int i=0;i<n;i++){
        aux[i]=vector[i];
    }
    //Ordenar meu vetor auxiliar:
    sort(aux,aux+n);
    int inicio=0;
    int fim=(n-1);
    long long a=0;
    long long b=0;
   
   while(inicio<fim){
        if(aux[inicio]+aux[fim]>x){
        fim--;
    }
        else if(aux[inicio]+aux[fim]<x){
        inicio++;
    }
        else if(aux[inicio]+aux[fim]==x){
        a=aux[inicio]; 
        b=aux[fim];
        break;
    }
    }
if(a==0){
    cout << y << "\n";
    return 0;
}
   //Busca Linear no vetor original:
   for(int i=0;i<n;i++){
    if(vector[i]==a){
        vector[i]=0;
        cout << (i+1) << " ";
        break;
    }
   }
    for(int i=0;i<n;i++){
    if(vector[i]==b){
        cout << (i+1);
        break;
    }
   }
}