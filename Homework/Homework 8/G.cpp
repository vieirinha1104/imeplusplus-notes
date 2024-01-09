#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,h;
    cin >> n >> h;
    //Matriz de de "0"s com h+1 linhas e n+3 colunas 
    vector<vector<long long>> dp(h+1,vector<long long>(n+3)),tree(h+1,vector<long long>(n+3));
    for(int j=1;j<=n;j++){
        for(int i=1;i<=h;i++){
            cin >> tree[i][j];
        }
    }
    //dp[i][j]: numero maximo de banana que ele consegue pegar com i movimentos, parando na posicao j antes de voltar para chao
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n;j++){
            if(j==1) dp[i][j]=(max(tree[i][j]+dp[i-1][j],tree[i][j]+dp[i-1][j+1]));
            else if(j==n) dp[i][j]=max(tree[i][j]+dp[i-1][j],tree[i][j]+dp[i-1][j-1]);
            else dp[i][j]=max(max(tree[i][j]+dp[i-1][j],tree[i][j]+dp[i-1][j-1]),tree[i][j]+dp[i-1][j+1]);
        }
    }
    long long ans=dp[h][1];
    for(int j=2;j<=n;j++) ans=max(ans,dp[h][j]);
    cout << ans << "\n";
    
}