#include <bits/stdc++.h>

using namespace std;
int chess[8][8];

bool check_board(int l,int c){
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    //row
    for(int i=0;i<8;i++){
        if(chess[l][i]==1){
            cnt1++;
        }
    }
    if(cnt1>1){
        return false;
    }
    //diagonal principal:
    int m=abs(l-c);
    int n=l+c;
    if(l>c){
        for(int i=0;i<8-m;i++){
            if(chess[i+m][i]==1){
                cnt2++;
            }
        }
    }
    else{
        for(int i=0;i<8-m;i++){
            if(chess[i][i+m]==1){
                cnt2++;
            }
        }
    }
    if(cnt2>1){
        return false;
    }
    //diagonal secundaria:
     for(int i=0;i<8;i++){
        if(n-i>=8 || n-i<0){
            continue;
        }
       if(chess[i][n-i]==1){
        cnt3++;
       }
    }
    if(cnt3>1){
        return false;
    }
    return true;
}

void backtracking(vector<int> &queens,int k){
    if(k==8){
        for(int i=0;i<8;i++){
            cout << queens[i] << " ";
        }
        cout <<"\n";
    }
    else{
        for(int i=0;i<8;i++){
            int aux=queens[k];
            queens[k]=i;
            chess[i][k]=1;
            if(check_board(i,k)){
                backtracking(queens,k+1);
                chess[i][k]=0;
                queens[k]=aux;
            }
            else{
                chess[i][k]=0;
                queens[k]=aux;
                continue;
            }
        }
    }
}

int main(){
   for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            chess[i][j]=0;
        }
    }
    vector<int> queens(8);
    backtracking(queens,0);

}