#include <bits/stdc++.h>
#define N 1000000
using namespace std;

vector<int> vis(N),cat(N),adj[N];
int n,m,ans;

void dfs(int u,int curl){
    vis[u]=1;
    if( adj[u].size()==1 and u!=1 ) ans++;
    if(cat[u]) curl++;
    if(!cat[u]) curl=0;
    for(auto e : adj[u]){
        if( !vis[e] and !cat[u] ) dfs(e,curl);
        if( !vis[e] and cat[u] ){
            if( curl+cat[e] <= m ) dfs(e,curl);
        }
    }
}

int main(){
    ans=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        cat[i]=a;
    }
    for(int i=1;i<n;i++){
        int a,b; cin >> a >> b;
        if(a==b) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout << ans << "\n";
}