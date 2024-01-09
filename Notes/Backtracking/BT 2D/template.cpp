#include <bits/stdc++.h>
#define INF 1e9

using namespace std;
typedef long long ll;

int board[9][9];
bool ok;

bool check(int x,int y);

void bt(int x,int y){
    if(x==9){
        ok=true;
        //printa a solucao
        return;
    } 
    if(board[x][y]!=0 and y!=8) bt(x, y+1);
    else if(board[x][y]!=0 and y==8) bt(x+1,0);
    else if(board[x][y]==0 and y!=8){
        for(int i=1;i<=9;i++){
            board[x][y]=i;
            if(check(x,y) and y!=8) bt(x,y+1);
            else if(check(x,y) and y==8) bt(x+1,0);
            board[x][y]=0; //Se chegar nessa linha, foi pq em algum momento deu pau, dai backtrack pro estado inicial
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin >> board[i][j];        
            }
        }
    }
}