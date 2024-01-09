#include <bits/stdc++.h>

using namespace std;

int main(){
    long long aux;
    int n;
    long long vector[1000];
    //entradas:
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> vector[i];
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
    if(n%2==0){
        cout << vector[(n/2)-1] << "\n";
    }
    else{
        cout << vector[(n/2)] << "\n";
    }
}