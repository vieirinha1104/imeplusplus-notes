#include <bits/stdc++.h>
#define INF 1e9
#define N 4000005

using namespace std;
typedef long long ll;

char board[2005][2005];
vector<int> adj[N];
int dis[N];
int h,w,start,finish,tam;

void bfs(int s){
    for(int i=0;i<N;i++){
        dis[i]=INF;
    }
    queue<int> q; q.push(s); int x; dis[s]=0;
    while(!q.empty()){
        x=q.front(); q.pop();
        for(auto e : adj[x]){
           if(dis[e]>dis[x]+1){ 
                q.push(e); dis[e]=dis[x]+1;
                if(e==finish) return;
            }           
        }
    }
}
bool check(int r,int c){
    if(r>=0 and r<h and c>=0 and c<w and board[r][c]=='.') return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    tam=h*w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> board[i][j]; 
            if(board[i][j]=='S'){
                board[i][j]='.'; start=(i*w+j);
            }
            else if(board[i][j]=='G'){
                board[i][j]='.'; finish=(i*w+j); 
            } 
        }
    }
    for(int i=0;i<h;i++){
        bool check=false;
        for(int j=0;j<w;j++){
            if(board[i][j]=='>') check=true;
            else if(board[i][j]=='.' and check==true) board[i][j]='!';
            else if(board[i][j]!='.' and board[i][j]!='!' and check==true) check=false;
        }
        check=false;
        for(int j=w-1;j>=0;j--){
            if(board[i][j]=='<') check=true;
            else if(board[i][j]=='.' and check==true) board[i][j]='!';
            else if(board[i][j]!='.' and board[i][j]!='!' and check==true) check=false;
        }
    }
    for(int j=0;j<w;j++){
        bool check=false;
        for(int i=0;i<h;i++){
            if(board[i][j]=='v') check=true;
            else if(board[i][j]=='.' and check==true) board[i][j]='!';
            else if(board[i][j]!='.' and board[i][j]!='!' and check==true) check=false;
        }
        check=false;
        for(int i=h-1;i>=0;i--){
            if(board[i][j]=='^') check=true;
            else if(board[i][j]=='.' and check==true) board[i][j]='!';
            else if(board[i][j]!='.' and board[i][j]!='!' and check==true) check=false;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j]=='.'){
                if(check(i+1,j)) adj[i*w+j].push_back((i+1)*w+j);
                if(check(i-1,j)) adj[i*w+j].push_back((i-1)*w+j);
                if(check(i,j+1)) adj[i*w+j].push_back(i*w+(j+1));
                if(check(i,j-1)) adj[i*w+j].push_back(i*w+(j-1));
            }
        }
    }
    bfs(start);
    if(dis[finish]==INF){
        cout << -1 << "\n"; return 0;
    } 
    cout << dis[finish] << "\n";
}