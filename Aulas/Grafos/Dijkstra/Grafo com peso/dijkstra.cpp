#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> adjw[100];
int dist[100];

void dijkstra (int s) {
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
   memset(dist,63,sizeof(dist));
   dist[s] = 0;
   pq.push({0, s});

   while (!pq.empty()) {
       int ud = pq.top().first;
       int u = pq.top().second; pq.pop();
       if (ud!=dist[u]) continue;
       for (auto x : adjw[u]) {
           int v = x.first;
           int w = x.second;
           if (dist[u]+w<dist[v]) {
               dist[v] = dist[u] + w;
               pq.push({dist[v], v});
           }
       }
   }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; long long c;
        cin >> a >> b >> c;
        adjw[a].push_back({b,c});
        adjw[b].push_back({a,c});
    }
    dijkstra(1);
    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
  
    
    
}