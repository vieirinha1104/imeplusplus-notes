#include <bits/stdc++.h>

using namespace std;

int n;
int chess[5][5];
int ans=0;

bool check(int l,int c){
   if(chess[l][c]==2) return false;
   //Checar esquerda:
   for(int i=c-1;i>=0;i--){
    if(chess[l][i]==2) break;
    if(chess[l][i]==1) return false;
   }
   //Checar direita:
   for(int i=c+1;i<n;i++){
    if(chess[l][i]==2) break;
    if(chess[l][i]==1) return false;
   }
   //Checar acima:
   for(int i=l-1;i>=0;i--){
    if(chess[i][c]==2) break;
    if(chess[i][c]==1) return false;
   }
    //Checar direita:
   for(int i=l+1;i<n;i++){
    if(chess[i][c]==2) break;
    if(chess[i][c]==1) return false;
   }
   return true;
}
int count(){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(chess[i][j]==1){
                cnt++;
            }
        }
    }
    return cnt;
}
void backtracking(int l,int c){ 
    if(c==n) ans=max(count(),ans); return;
    if(check(l,c)) chess[l][c]=1; 
    if(l != n-1) backtracking(l+1,c);
    else backtracking(0,c+1);
    if(chess[l][c]==1){ 
        chess[l][c]=0;
        if(l != n-1) backtracking(l+1,c);
        else backtracking(0,c+1);
    }
}

int main(){
   cin >> n;
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char a;
            cin >> a;
            if(a=='.') chess[i][j]=0;
            if(a=='X') chess[i][j]=2;
        }
    }
    backtracking(0,0);
    cout << ans <<"\n";

}