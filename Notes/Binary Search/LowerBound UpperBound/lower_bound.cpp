#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int v[N];
//Voce quer saber se um elemento esta na lista, e se estiver, retornar a posicao da primeira aparicao
//Solucao: usar lower_bound
//Lower bound: retornar o primeiro elemento nao menor que key(ou seja o primeiro elemento >= key)
//Uper bound: >key
int main(){ 
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    int key,pos;
    cin >> key;
    sort(v,v+n);
    int l=0,r=n-1;
    while(l<r){
       int m=(l+r)/2;
       if(v[m]<key) l=m+1;
       else r=m;
    }
    pos=l;
    if(v[pos]!=key) cout << -1 << "\n"; // nao esta na lista, v[pos] vai ser o primeiro elemento maior q key que esta na lista
    else cout << pos << "\n";
}