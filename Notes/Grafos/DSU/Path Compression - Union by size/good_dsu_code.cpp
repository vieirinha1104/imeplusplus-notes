#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int par[N],sz[N];
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
void unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x];
    par[x]=y; //Ligar sempre o menor no maior, para melhorar a complexidade
}
int main(){
    for(int i=0;i<N;i++){
        par[i]=i; sz[i]=1;
    }
}