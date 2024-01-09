#include <bits/stdc++.h>
using namespace std;
//No sudoku temos 9 blocos 3x3, em que nesses blocos nao podem ter numeros repetidos
//Portanto faremos um array de 9 matrizes
int board[9][9];
bool check_blocks[9][3][3],ok; 

bool check(int l,int c, int k){
    int x=l/3;
    for(int i=0;i<9;i++) if(i!=l and board[i][c]==k) return false; //Verifica a coluna
	for(int i=0;i<9;i++) if(i!=c and board[l][i]==k) return false; //Verifica a linha
    return !check_blocks[3*x+(c/3)][(k-1)/3][(k-1)%3]; //Veririca se o numero esta no bloco
}

void bt(int l,int c){
    if(l==9){
        // Se ele chegar ate aqui, foi pq ele conseguiu preencher o sudoku completo
        // Entao printa a solucao que ele achou, pois as outras chamadas de funcao vao mudar o tabuleiro
        ok=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    else if(board[l][c]){
        if(c==8) bt(l+1,0);
        else bt(l,c+1);
    }
    else{
        for(int i=1;i<=9;i++){
            if(check(l,c,i)){
                int x=l/3;
                board[l][c]=i;
                check_blocks[3*x+(c/3)][(i-1)/3][(i-1)%3]=true;
                if(c==8) bt(l+1,0);
                else bt(l,c+1);
                //Se ele chegar nessa linha de codigo, eh pq deu pau, entao backtrack pro estado inicial
                board[l][c]=0;
                check_blocks[3*x+(c/3)][(i-1)/3][(i-1)%3]=false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    for(int k=0;k<t;k++){
        ok=false;
        memset(check_blocks,0,sizeof(check_blocks));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin >> board[i][j]; int x=i/3;
                if(board[i][j]) check_blocks[3*x+(j/3)][(board[i][j]-1)/3][(board[i][j]-1)%3]=true;
            }
        }
        bt(0,0);
        if(!ok) cout << "No solution\n";
    }
}