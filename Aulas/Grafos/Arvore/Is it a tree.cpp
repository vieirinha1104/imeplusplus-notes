#include <bits/stdc++.h>
#define N 1000000

using namespace std;

int n,m;
vector<int> adj[N],vis(N),color(N);
bool check;

void bfs(int s) {
   queue<int> q;
   vis[s]=1;
   color[s]=0;
   q.push(s);
   while (!q.empty()) {
       int u = q.front(); q.pop();
       for (auto x : adj[u]){
            if(color[x]==-1){
                color[x]=1-color[u];
                if(!vis[x]){ 
                    vis[x]=1;
                    q.push(x);
                }   
            } 
            else if(color[x]!=-1 and color[x]==color[u]){
                check=false;
                return;
            }
        }
    }
}

int main(){
    int t;
    for(int i=0;i<t;i++){
        for(int j=1;j<=2000;j++){
            vis[j]=0;
            color[j]=-1;
        }
        cin >> n >> m;
        for(int j=0;j<m;j++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        check=true;
        for(int j=1;j<=2000;j++){
            if(!check) break;
            if(!vis[j]) bfs(j);
        }
        if(check) cout << "Scenario #:" << t+1 << "\n" << "Suspicious bugs found!\n";
        else cout << "Scenario #:" << t+1 << "\n" << "No suspicious bugs found!\n";
        for(int i=1;i<=2000;i++) adj[i].clear();
        

    }
}