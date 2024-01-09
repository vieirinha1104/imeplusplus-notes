#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int vis[N],dis[N],stop;
vector<int> adj[N];

bool ispr(int x) {
    for(int i=2; i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
void bfs(int s){
    for(int i=1;i<N;i++){
        vis[i]=0; dis[i]=0;
    }
    queue<int> q; q.push(s); int x; vis[s]=1;
    while(!q.empty()){
        x=q.front(); q.pop();
        for(auto e : adj[x]){
           if(!vis[e] and ispr(e)){ 
                vis[e] = 1;
                q.push(e); dis[e]=dis[x]+1;
                if(e==stop){
                    return;
                }
            }           
        }
    }
}
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        string root,goal; int start;
        cin >> root >> goal;
        //Vamos calcular o nosso goal e raiz:
        stringstream ss1; ss1 << goal;  ss1 >> stop;
        stringstream ss2; ss2 << root;  ss2 >> start;
        //Vamos calcular as adjacencias
        for(int i=1000;i<10000;i++){
            int u,d,c,m;
             u=i%10; d=((i-u)/10)%10; c=((((i-u)/10)-d)/10)%10; m=i/1000;
            //unidade
            for(int j=0;j<=9;j++){
                if(j==u) continue;;
                int v=1000*m+100*c+10*d+j;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
            //dezena
            for(int j=0;j<=9;j++){
                if(j==d) continue;
                int v=1000*m+100*c+10*j+u;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
            //centena
            for(int j=0;j<=9;j++){
                if(j==c) continue;
                int v=1000*m+100*j+10*d+u;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
            //milhar
            for(int j=1;j<=9;j++){
                if(j==m) continue;
                int v=1000*j+100*c+10*d+u;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }
        bfs(start);
        if(!vis[stop]) cout << "Impossible\n";
        else cout << dis[stop] << "\n";
        for(int i=1000;i<10000;i++){
            adj[i].clear();
        }
    }
}
