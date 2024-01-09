#include <bits/stdc++.h>
#define N 100 //O chess board so tem 64 casas, entao nao tem necessidade de um N mt grande
//Quando coloquei define N 1000005 deu TLE, mudei para N 100 e passou
using namespace std;

int dis[N],l2,c2;
vector<int> adj[N];
map<pair<int,int>,int> m;

bool check(int l,int c){
    if(l>=0 and l<8 and c>=0 and c<8) return true;
    return false;
}
void bfs(int s){
    memset(dis,63,sizeof(dis));
    queue<int> q; q.push(s); int x; dis[s]=0;
    while(!q.empty()){
        x=q.front(); q.pop();
        for(auto e : adj[x]){
           if(dis[e]>dis[x]+1){ 
                q.push(e); dis[e]=dis[x]+1;
                if(e==m[{l2,c2}]) return;
            }           
        }
    }
}
int main(){
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        int key=1;
        string start,finish;
        cin >> start >> finish;
        int l1=start[0]-'a'; int c1=start[1]-'1';
        l2=finish[0]-'a'; c2=finish[1]-'1';
        //Vamos mapear cada casa do meu chess em um inteiro, ou seja, meus nodes do grafo
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                m.insert({{i,j},key++});
            }
        }
        //Vamos montar nossa lista de adjacencias do grafo
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(check(i+2,j+1)) adj[m[{i,j}]].push_back(m[{i+2,j+1}]);
                if(check(i+2,j-1)) adj[m[{i,j}]].push_back(m[{i+2,j-1}]);
                if(check(i-2,j+1)) adj[m[{i,j}]].push_back(m[{i-2,j+1}]);
                if(check(i-2,j-1)) adj[m[{i,j}]].push_back(m[{i-2,j-1}]);
                if(check(i+1,j+2)) adj[m[{i,j}]].push_back(m[{i+1,j+2}]);
                if(check(i-1,j+2)) adj[m[{i,j}]].push_back(m[{i-1,j+2}]);
                if(check(i+1,j-2)) adj[m[{i,j}]].push_back(m[{i+1,j-2}]);
                if(check(i-1,j-2)) adj[m[{i,j}]].push_back(m[{i-1,j-2}]);
            }
        }
        //um simples bfs finaliza a questao
        bfs(m[{l1,c1}]);
        cout << dis[m[{l2,c2}]] << "\n";
        m.clear();
    }
}
