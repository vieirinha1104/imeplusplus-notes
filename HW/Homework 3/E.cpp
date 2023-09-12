#include <bits/stdc++.h>
#define N 1000000

using namespace std;

int n,t;
vector<int> adj[N];
vector<int> vis(N);

void dfs(int u){
    vis[u]=1;
    for(auto e : adj[u]){
        if(!vis[e]) dfs(e);
    }
}

int main(){
    cin >> n >> t;
    for(int i=1;i<=n-1;i++){
        int a; cin >> a;
        if(i+a>n) continue;
        else adj[i].push_back(i+a);
    }
    dfs(1);
    if(vis[t]) cout << "YES\n";
    else cout << "NO\n";
    return 0;   
}