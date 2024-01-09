#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int par[N + 1]; int sz[N + 1],comp;
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
bool unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return true;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x]; 
    par[x]=y; comp--; //Ligar sempre o menor no maior, para melhorar a complexidade
    return false;
}
int main(){
   int n;
   vector<pair<int,int>> closed_edges; 
   vector<int> lideres;
   cin >> n;
   comp=n;
   for(int i=1;i<=N;i++){
        par[i]=i; sz[i]=1;
    }
   for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        if(unite(a,b)) closed_edges.push_back({a,b}); //Se o caminho nao alterar a conexidade do grafo, ele pode ser removido
    }
    for(int i=1;i<=n;i++){
        if(par[i]==i) lideres.push_back(i); // se houver mais de um lider, o grafo nao eh todo conexo
        // adicionar uma rota entre dois lideres diminui o numero de componentes conexos
    }
    if(comp == 1){ // entao a cidade ja eh toda conexa
        cout << 0 << "\n";
        return 0;
    }
    else{
        int x= comp - 1; cout << x << "\n";
        for(int i=0;i<x;i++){
            cout << closed_edges[i].first << " " << closed_edges[i].second << " " << lideres[lideres.size() -1] << " " << lideres[lideres.size() -2] << "\n";
            unite(lideres[lideres.size()-1],lideres[lideres.size()-2]);
            lideres.pop_back(); int x = find(lideres[lideres.size()-1]); lideres[lideres.size()-1]=x; 
        }
    }
   
}
