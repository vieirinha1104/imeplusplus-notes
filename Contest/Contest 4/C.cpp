#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<pair<int,int>> adjw[N];
int dist[N];

void dijkstra(int s){
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
   memset(dist,63,sizeof(dist));
   dist[s]=0;
   pq.push({0,s});
   while(!pq.empty()){
       int ud=pq.top().first;
       int u=pq.top().second; 
       pq.pop();
       if(ud!=dist[u]) continue;
       for(auto x : adjw[u]){
           int v=x.first;
           int w=x.second;
           if(dist[u]+w<dist[v]){
               dist[v]=dist[u]+w;
               pq.push({dist[v],v});
           }
       }
   }
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==b) continue;
        adjw[a].push_back({b,c});
        adjw[b].push_back({a,c});
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        dijkstra(x);
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            if(dist[i]>1e9) continue;
            if(ans1<dist[i]) ans1=dist[i];
        }
        for(int i=0;i<n;i++){
            if(dist[i]>1e9) continue;
            if(ans1==dist[i]) ans2++;
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    
    
    
}