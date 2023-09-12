#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    int n= s.size();
    int aux=0; // para verificar se nao eh so 11111
    int auxx=0;
    int j=0; // verificar quando aparece o primeiro zero
    int vector[100000];
    for(int i=0;i<n;i++){
        aux++;
        if(s[i]=='0' && auxx==0){
            auxx++;
            i++;
            }
        vector[j]=(s[i]-48);
        j++;
    }
    if(aux==n){
        for(int i=0;i<n-1;i++){
            cout << 1;
        }
        return 0;

    }
        for(int i=0;i<n-1;i++){
            cout << vector[i];
        }
    }
