#include <bits/stdc++.h>
using namespace std;

const int N=105,INF=1e9;
vector<int> depht(N),adj[N],vis(N),par(N);
//Mesma ideia do merge sort, algoritmo de divide and conquer
void setTree(vector<int> &l,int t){
    if(!l.size()) return;
    pair<int,int> p={l[0],0};
    for(int i=1;i<l.size();i++){
        if(p.first<l[i]) p={l[i],i};
    }
    par[p.first]=t;
    vector<int> u; vector<int> v;
    for(int i=0;i<p.second;i++) u.push_back(l[i]);
    for(int i=p.second+1;i<l.size();i++) v.push_back(l[i]);
    setTree(u,p.first); setTree(v,p.first);
}
//Dfs padrao pra pegar o nivel de cada node da arvore
void dfs(int u){
   vis[u]=1;
   for(auto v : adj[u]){ 
        if(!vis[v]){
            depht[v]=depht[u]+1;
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        int n,root;
        vector<int> v;
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        //Montar a arvore
        setTree(v,-1);
        //Montei a arvore implicitamente, atraves da lista de parentes de cada no, agora montar o grafo direcionado
        for(int x : v){
            if(par[x]==-1) root=x;
            else adj[par[x]].push_back(x);
        }
        dfs(root);
        for(int i=0;i<n;i++) cout << depht[v[i]] << " ";
        cout << "\n";
        for(int i=0;i<N;i++){ 
            adj[i].clear(); vis[i]=0; par[i]=0; depht[i]=0;
        }

    }  
}