#include <bits/stdc++.h>
#define N 2005

using namespace std;

int n,m;
vector<int> adj[N],color(N,-1);
bool check;

void bfs(int s) {
   queue<int> q;
   if(color[s]!=-1) return;
   color[s]=0;
   q.push(s);
   while (!q.empty()) {
       int u = q.front(); q.pop();
       for (auto x : adj[u]){
            if(color[x]==-1){
                color[x]=1-color[u];
                q.push(x);
            } 
            else if(color[x]!=-1 and color[x]==color[u]){
                check=true;
                return;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        for(int j=1;j<=2000;j++){
            color[j]=-1;
        }
        cin >> n >> m;
        for(int j=0;j<m;j++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        check=false;
        for(int j=1;j<=n;j++){
            if(check) break;
            bfs(j);
        }
        if(check) cout << "Scenario #" << i+1 << ":" << "\n" << "Suspicious bugs found!\n";
        else cout << "Scenario #" << i+1 << ":" << "\n" << "No suspicious bugs found!\n";
        for(int j=1;j<=2000;j++) adj[j].clear();
    }
}