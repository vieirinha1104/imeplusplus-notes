#include <bits/stdc++.h>
using namespace std;
vector<int> vis(5);
vector<int> v(4);
bool check(){
    if(2*v[0]+3*v[1]+7*v[2]+11*v[3]<=49) return true;
    else return false;
}
void backtracking(int k){
    if(k==4 and 2*v[0]+3*v[1]+7*v[2]+11*v[3]==49){
        //Printa a solucao
        for(int i=0;i<4;i++){
            cout << v[i] << " ";
        }
        cout << "\n"; return;
    }
    for(int i=0;i<=4;i++){
        int aux = v[k];
        if(!vis[i]){
            v[k]=i; vis[i]=1;
        }
        else continue;
        if(check()) backtracking(k+1);
        v[k]=aux; vis[i]=0; //Backtrack pro estado anterior
    }
}
int main(){
    backtracking(0);
}