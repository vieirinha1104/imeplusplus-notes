#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    long long vector[200000];
    //entradas:
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> vector[i];
    }
    //ordenar o array:
    sort(vector,vector+n);
   //Algoritmo:
    long long aux=1;
    long long auxx=vector[0];
    for(int i=1;i<n;i++){
        if(auxx!=vector[i]){
            auxx=vector[i];
            aux++;
        }
    }
    //saida:
    cout << aux << "\n";
}