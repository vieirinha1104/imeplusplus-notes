#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
vector<int> vis(100);

void bfs(int s) {
   queue<int> q;
   cout << s;
   vis[s] = 1;
   q.push(s);
   while (!q.empty()) {
       int u = q.front(); q.pop();
       for (auto x : adj[u]){
            if(!vis[x]){ 
                vis[x]=1;
                cout<<x; 
                q.push(x);
            }   
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
    bfs(1);
  
    
    
}