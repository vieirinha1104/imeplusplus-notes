#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int par[N],sz[N],arr[N],n,ans;
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
void unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x];
    par[x]=y;//Ligar sempre o menor no maior, para melhorar a complexidade
    ans--; 
}
int main(){
    //Basicamente, a questao vai te dar N nos desconexos, e vai ficar unindo i com arr[i]
    //E pede para voce dizer quantos componentes desconexos esse conjunto tem
    for(int i=0;i<N;i++){
        par[i]=i; sz[i]=1;
    }
    cin >> n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        if(find(i)!=find(arr[i])) unite(i,arr[i]);
    }
    cout << ans << "\n";
}