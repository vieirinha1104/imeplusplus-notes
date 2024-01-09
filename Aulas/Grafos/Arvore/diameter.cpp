#include <bits/stdc++.h>
#define N 100005
using namespace std;

int vis[N],dis[N];
vector<int> adj[N];
int bfs(int s){
    for(int i=1;i<N;i++){
        vis[i]=0; dis[i]=0;
    }
    vis[s]=1;
    queue<int> q; q.push(s); int x;
    while(!q.empty()){
        x=q.front(); q.pop();
        for(auto e : adj[x]){
           if(!vis[e]){ 
                vis[e]=1; q.push(e); dis[e]=dis[x]+1;
            }           
        }
    }
    return x;
}
int main(){
    int n,m;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int u=bfs(1);
    int v=bfs(u);
    cout << dis[v] << "\n";
}