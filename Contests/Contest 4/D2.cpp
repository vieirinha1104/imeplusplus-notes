#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int par[N],sz[N],milk[N];
long long ans;
vector<int> milkmen;
vector<pair<long long,pair<int,int>>> edges; // (dist, (node a,node b) )

int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}

bool unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return false;
    //Se os dois vertices da aresta forem milkman, nao tem pq realizar esse custo
    else if(milk[x] and milk[y]) return false; 
    //Se um dos vertices da aresta for um milkman e outro nao, faremos a uniao desses conjuntos
    //E o lider vai ser o vertice que eh milkman
    else if(milk[x]){
        sz[x]+=sz[y];
        par[y]=x;
    }
    else if(milk[y]){
        sz[y]+=sz[x];
        par[x]=y;
    }
    //DSU tradicional
    else{
        if(sz[x]>sz[y]) swap(x,y);
        sz[y]+=sz[x];
        par[x]=y; //Ligar sempre o menor no maior, para melhorar a complexidade
    }
    return true;
}

void kruskal(){
    ans=0; 
    sort(edges.begin(),edges.end());
    for(auto e : edges){
        int w= e.first; int a=(e.second).first; int b=(e.second).second;
        int m=find(a); int n=find(b);
        if(unite(m,n)) ans+=w;
    }
}

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        for(int i=0;i<N;i++){
            par[i]=i; sz[i]=1;
        }   
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> milk[i];
            if(milk[i]) milkmen.push_back(i);
        }
        for(int i=0;i<m;i++){
            int a,b; 
            long long c;
            cin >> a >> b >> c;
            edges.push_back({c,{a,b}});
        }
        kruskal();
        int check=0;
        for(auto x : milkmen) check+=sz[x];
        if(check==n) cout << ans << "\n";
        else cout << "impossible\n";
        edges.clear();
        milkmen.clear();    
    }
}
