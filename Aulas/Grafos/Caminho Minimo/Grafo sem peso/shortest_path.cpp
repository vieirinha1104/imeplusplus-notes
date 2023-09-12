#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
int dist[100];

void shortest_path(int s) {
  queue<int> q;
  memset(dist,63,sizeof(dist));
   dist[s] = 0;
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
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    shortest_path(0);
    for(int i=0;i<n;i++){
        cout << dist[i] << " ";
    }
  
    
    
}