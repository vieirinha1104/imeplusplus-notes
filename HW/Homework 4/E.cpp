#include <bits/stdc++.h>
#define N 1000000
using namespace std;
using ll = long long;
vector<pair<ll,ll>> adjw[N];
vector<ll> vis(N);
ll ans;

void prim (int s) {
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
   pq.push({0, s});
   ans=0;
   while (!pq.empty()) {
       ll uw = pq.top().first;
       ll u = pq.top().second; pq.pop();
       if (vis[u]) continue;
       vis[u]=1; ans+=uw;
       for (auto x : adjw[u]) {
           int v = x.first;
           int w = x.second;
           if (!vis[v]) pq.push({w, v});
       }
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
    prim(1);
    cout << ans << "\n";    
}