#include <bits/stdc++.h>
#define INF 1e9

using namespace std;
typedef long long ll;

bool check_board[2005][2005];
char board[2005][2005];
int dis[2005][2005];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int h,w;
pair<int,int> start,finish;

bool check_adj(int x,int y){
    if(x>=0 and x<h and y>=0 and y<w and board[x][y]=='.') return true;
    return false;
}

void bfs(pair<int,int> s){
    int r=s.first;
    int c=s.second; 
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dis[i][j]=INF;
        }
    }
    queue<pair<int,int>> q; 
    q.push({r,c}); 
    dis[r][c]=0;
    while(!q.empty()){
        pair<int,int> aux=q.front(); 
        q.pop();
        int x=aux.first;
        int y=aux.second;
        for(int i=0;i<4;i++){
            if(!check_adj(x + dx[i],y + dy[i])) continue;
            int a=dis[x + dx[i]][y + dy[i]];
            if( a > (dis[x][y] + 1) ){ 
                q.push({x + dx[i],y + dy[i]}); 
                dis[x + dx[i]][y + dy[i]]=dis[x][y]+1;
                if(x + dx[i]==finish.first and y + dy[i] == finish.second) return;
            }           
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> board[i][j];
            if(board[i][j]=='S'){
                board[i][j]='.'; 
                start={i,j};
            }
            else if(board[i][j]=='G'){
                board[i][j]='.'; 
                finish={i,j}; 
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
    bfs(start);
    if(dis[finish.first][finish.second]==INF){
        cout << -1 << "\n"; 
        return 0;
    } 
    cout << dis[finish.first][finish.second] << "\n";
    return 0;
}