#include <bits/stdc++.h>
#define N 2005
using namespace std;

int par[N];
vector<int> rk(N,1); //rk de rank

void recover(int s){
    int u=par[s];
    while(u!=-1){
        u=par[u]; rk[s]++;
    }
}

int main(){ 
    int n;
    int ans=0;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> par[i];
    for(int i=1;i<=n;i++){
        recover(i);
        ans=max(ans,rk[i]);
    }
   cout << ans << "\n";
}