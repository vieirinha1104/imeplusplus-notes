#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int par[N],sz[N],ans;
vector<pair<int,pair<int,int>>> edges; // (dist, (node a,node b) )
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
int unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x];
    par[x]=y; //Ligar sempre o menor no maior, para melhorar a complexidade
}
void kruskal(){
    ans=0; sort(edges.begin(),edges.end());
    for( auto e : edges ){
        int w= e.first; int a=(e.second).first; int b=(e.second).second;
        //Vamos olhar para a aresta de menor peso, se os dois vertices nao estiverem no mesmo conjunto do DSU: join
        int m=find(a); int n=find(b);
        if(m!=n){ 
            unite(m,n); ans+=w;
        }
    }
}
int main(){
    int ans=0;
    for(int i=0;i<N;i++){
        par[i]=i; sz[i]=1;
    }
}