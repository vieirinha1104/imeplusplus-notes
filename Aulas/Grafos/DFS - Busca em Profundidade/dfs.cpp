#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
vector<int> vis(100);

void dfs(int s){
    vis[s]=1;
    cout << s;
    for(auto x : adj[s]){
        if(!vis[x]){
            dfs(x);
        }
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
  
    
    
}