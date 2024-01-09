#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e6;
vector<pair<int,ll>> adjw[N];
vector<int>root;
int vis[N],milk[N],n;
ll ans;
//Basicamente, o problema se trata de formar florestas de MST
//Onde cada arvore da floresta tem como raiz um milkman
//Para isso, so colocar todos os milkman no heap antes de fazer o prim
void prim(){
    ans=0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for(auto x : root) pq.push({0,x});
    memset(vis,0,sizeof(vis));
    while(!pq.empty()){
        ll uw=pq.top().first;
        ll u=pq.top().second; 
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        n--; 
        ans+=uw;
        for(auto x : adjw[u]){
            int v=x.first;
            int w=x.second;
            if(!vis[v]) pq.push({w,v});
        }
    }
}

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        int m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> milk[i];
            if(milk[i]) root.push_back(i);
        }
        for(int i=0;i<m;i++){
            int a,b; ll c;
            cin >> a >> b >> c;
            adjw[a].push_back({b,c});
            adjw[b].push_back({a,c});
        }
        prim();
        if(!n) cout << ans << "\n";
        else cout << "impossible\n";
        for(int i=0;i<N;i++) adjw[i].clear();
        root.clear();    
    }
}