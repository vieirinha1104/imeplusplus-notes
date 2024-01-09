#include <bits/stdc++.h>
using namespace std;

int dist[101];
vector<pair<int,int>> adjw[101];
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
    int t;
    cin >> t;
    while(t--){ 
        int n,goal,timelimit,m; int ans=0;
        cin >> n >> goal >> timelimit >> m;
        for(int i=0;i<m;i++){
            int a,b; long long c;
            cin >> a >> b >> c;
            adjw[b].push_back({a,c});
        }
        dijkstra(goal);
        for(int i=1;i<=n;i++){
            if(dist[i]<=timelimit) ans++; 
        }
        cout << ans << "\n";
        if(t){
            cout << "\n";
        }
        for(int i=0;i<100;i++){
            adjw[i].clear();
        }
    }
}