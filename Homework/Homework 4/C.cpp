#include <bits/stdc++.h>
#define N 1000000
using namespace std;
using ll = long long;
vector<pair<ll,ll>> adjw[N];
vector<ll> ans;
ll dist[N];
vector<ll> par(N);

void dijkstra (int s) {
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
   memset(dist,63,sizeof(dist));
   dist[s] = 0;
   par[s] = s;
   pq.push({0, s});

   while (!pq.empty()) {
       ll ud = pq.top().first;
       ll u = pq.top().second; pq.pop();
       if (ud!=dist[u]) continue;
       for (auto x : adjw[u]) {
           int v = x.first;
           int w = x.second;
           if (dist[u]+w<dist[v]) {
               dist[v] = dist[u] + w;
               pq.push({dist[v], v});
               par[v]=u;
           }
       }
   }
}
void recovery(int goal){
    ans.push_back(goal);
    while(par[goal]!=goal){
        goal=par[goal];
        ans.push_back(goal);
    }
}
int main(){
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll a,b; ll c;
        cin >> a >> b >> c;
        if(a==b) continue;
        adjw[a].push_back({b,c});
        adjw[b].push_back({a,c});
    }
    dijkstra(1); recovery(n);
    if(par[n]==0){
        cout << "-1\n"; return 0;
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
    cout <<"\n";    
}