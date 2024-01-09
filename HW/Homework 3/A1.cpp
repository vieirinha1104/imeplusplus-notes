#include <bits/stdc++.h>
#define N 1000000
using namespace std;
//Solucao por grafos, usando BFS, montando a matriz de adj
int dis[N],n,m;
vector<int> adj[N];
void bfs(int s){
    memset(dis,63,sizeof(dis));
    dis[s]=0;
    queue<int> q; q.push(s); int x;
    while(!q.empty()){
        x=q.front(); q.pop();
        for(auto e : adj[x]){
           if(dis[e]>dis[x]+1){ 
                q.push(e); dis[e]=dis[x]+1;
                if(e==m) return;
            }           
        }
    }
}
int main(){
        cin >> n >> m;
        //Vamos calcular as adjacencias
        for(int i=1;i<=10000;i++){
            int a=i-1; int b=i*2;
            adj[i].push_back(a);
            adj[i].push_back(b);
        }
        bfs(n);
        cout << dis[m] << "\n";
    
}
