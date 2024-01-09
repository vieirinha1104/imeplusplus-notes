#include <bits/stdc++.h>
#define N 1000000

using namespace std;

int n,sz[N];
vector<int> adj[N],vis(N),cent;

void dfs(int s){
    bool check=true;
    vis[s]=1; sz[s]=1;
    for(auto x : adj[s]){
        if(!vis[x]){
            dfs(x);
            sz[s]+=sz[x];
            if(2*sz[x]>n) check=false;
        }
    }
    if(check and (2*(n-sz[s])<=n)) cent.push_back(s);
}

int main(){
    cin >> n;
    for(int i=1;i<=(n-1);i++){
        int a,b; cin >> a >> b;
        if(a==b) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1); 
    for(auto e : cent){
        cout << e << "\n";
    }
   
}

