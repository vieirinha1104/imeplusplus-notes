#include <bits/stdc++.h>
using namespace std;
vector<int> vis(5);
vector<int> v(4);
bool check(){
    if(2*v[0]+3*v[1]+7*v[2]+11*v[3]<=49) return true;
    else return false;
}
void backtracking(int k){
    if(k==5 and 2*v[0]+3*v[1]+7*v[2]+11*v[3]==49){
        for(auto x : v) cout << x << " ";
        cout << "\n"; 
        return;
    }
    for(int i=0;i<=4;i++){
        if(!vis[i]){
            int aux = v[k];
            v[k]=i; 
            vis[i]=1;
            if(check()) backtracking(k+1);
            v[k]=aux; 
            vis[i]=0;
        }
    }
}
int main(){
    backtracking(0);
}