#include <bits/stdc++.h>
using namespace std;
int n,ans;
char board[4][4];
char moves[2]={'o','.'};

bool check(int x,int y){
    if(board[x][y]=='X') return false;
    //right
    for(int i=y+1;i<n;i++){
        if(board[x][i]=='X') break;
        if(board[x][i]=='o') return false;
    }
    //left
     for(int i=y-1;i>=0;i--){
        if(board[x][i]=='X') break;
        if(board[x][i]=='o') return false;
    }
    //down
    for(int i=x+1;i<n;i++){
        if(board[i][y]=='X') break;
        if(board[i][y]=='o') return false;
    }
    //up
    for(int i=x-1;i>=0;i--){
        if(board[i][y]=='X') break;
        if(board[i][y]=='o') return false;
    }
    return true;
}

void bt(int x,int y,int curl){
    if(x==n){
        ans=max(ans,curl); return;
    }
    else if(board[x][y]=='X' and y==n-1) bt(x+1,0,curl);
    else if(board[x][y]=='X' and y!=n-1) bt(x,y+1,curl);
    else if(board[x][y]=='.'){
        char aux=board[x][y];
        for(int i=0;i<2;i++){
            if(check(x,y) and !i){
                board[x][y]=moves[i];
                if(y!=n-1) bt(x, y+1,curl+1);
                else bt(x+1,0,curl+1);
                board[x][y]=aux;
            }
            //Cuidado, pode ser que seja permitido colocar uma pedra numa casa, 
            // mas pode ser que ela nao traga a configuracao maxima de pedras totais
            // Entao se check(x,y) retorna true, podemos tanto colocar uma pedra como passar
            else if(check(x,y) and i){
                board[x][y]=moves[i];
                if(y!=n-1) bt(x, y+1,curl);
                else bt(x+1,0,curl);
                board[x][y]=aux;
            }
            else if(!check(x,y)){
                if(y!=n-1) bt(x, y+1,curl);
                else bt(x+1,0,curl);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    while(true){
		cin >> n; 
		ans=0;
		if(n==0) break;
		for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> board[i][j];
            }
        }
		bt(0,0,0);
		cout << ans << '\n';
	}
}