#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5,INF=1e9;
vector<int> adj[N],dist(N,INF),vis(N),sz(N),v;
//Essa eh dificil
//Nao precisa desse shortest_path, o dfs consegue rotular os depht de cada no, mas como tentei inicialmente assim
//deixei como tava
void shortest_path(int s) {
  queue<int> q;
   dist[s] = 1;
   q.push(s);
   while (!q.empty()) {
       int u = q.front(); q.pop();
       for (auto x : adj[u]){
            if(dist[x] > dist[u] + 1) {
                dist[x] = dist[u] + 1;
                q.push(x);
            }
        }
    }
}

void dfs(int u){
   sz[u]=1; vis[u]=1;
   for(auto v : adj[u]){ 
        if(!vis[v]){
            dfs(v);
            sz[u]+=sz[v];
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    shortest_path(1);
    dfs(1);
    for(int i=1;i<=n;i++) v.push_back(dist[i]-sz[i]);
    sort(v.begin(),v.end());
    long long ans=0;
    for(int i=1;i<=k;i++){
        ans+=v[v.size()-i];
    }
    cout << ans << "\n";
    return 0;    
}