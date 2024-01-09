#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int par[N],rk[N]; //existe uma biblioteca rank no c++, entao para nao haver ambiguidade mudar para 'rk'
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
bool unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return true;
    else{
        if(rk[x]<rk[y]){
            par[x]=y;
        }
        else if(rk[x]==rk[y]){ 
            par[x]=y;
            rk[y]++;//a altura so aumenta se os dois conjuntos que serao unidos tiverem a msm altura
        } 
        else{
            par[y]=x; //Ligar sempre o menor no maior, para melhorar a complexidade
        }
        return false;
    }
}
int main(){
    for(int i=1;i<N;i++){
        par[i]=i; rk[i]=0;
    }
    unite(1,2); unite(3,4); unite(1,4);
    int x=find(1);
    cout << rk[x] << "\n";
}