#include <bits/stdc++.h>
#define N 200005
#define INF 1e9
using namespace std;

vector<int> adj[N],dist(N);

void shortest_path(int s) {
  memset(dist,63,sizeof(dist));
  queue<int> q;
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
    shortest_path(1);
    
    
}