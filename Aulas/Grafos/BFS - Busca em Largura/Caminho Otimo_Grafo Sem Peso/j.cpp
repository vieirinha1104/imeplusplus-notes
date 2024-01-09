#include <bits/stdc++.h>
#define N 4000005
using namespace std;
vector<pair<int,long long>> adjw[N];
double dist[N];
int n,m;
void dijkstra (int s) {
  priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
   for(int i=1;i<=n;i++){
        dist[i]=N;
    }
   dist[s] = 0; pq.push({0, s});
   while (!pq.empty()) {
        double ud = pq.top().first; int u = pq.top().second; pq.pop();
       if (ud!=dist[u]) continue;
       for (auto x : adjw[u]) {
           int v = x.first;
           long long w = x.second;
           if (dist[u]+log(w)<dist[v]) {
               dist[v] = dist[u] + log(w);
               pq.push({dist[v], v});
           }
       }
   }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; long long c;
        cin >> a >> b >> c;
        if(a==b) continue;
        adjw[a].push_back({b,c});
        adjw[b].push_back({a,c});
    }
    dijkstra(1);
    double ans=dist[n]/log(7);
    cout << setprecision(16) << ans << "\n";   
}