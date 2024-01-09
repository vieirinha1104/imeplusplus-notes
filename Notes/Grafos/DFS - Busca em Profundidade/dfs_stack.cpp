#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
vector<int> vis(100);

void dfs(int u){
    stack<int> s;
    s.push(u);
    while(!s.empty()){
        int u=s.top();
        s.pop();
        vis[u]=1;
        cout << u;
        for(int i=adj[u].size()-1;i>=0;i--){
//Cuidado, na stack, ele processa primeiro os verticies adjacentes a u da direita para esquerda
            int x=adj[u][i];
            if(!vis[x]){
                s.push(x);
            }
        }
    }

}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
}