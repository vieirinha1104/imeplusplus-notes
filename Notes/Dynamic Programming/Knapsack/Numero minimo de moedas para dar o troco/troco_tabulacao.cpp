#include <bits/stdc++.h>
using namespace std;
#define N 1005
const int INF = 0x3f3f3f3f;
long long dp[100][100005];
int main(){
    int n,w;
    vector<int> coins;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        int x; cin >> x; coins.push_back(x);
    } 
    //Inicializando a primeira linha da matriz dp
    for(int i=1;i<100;i++) dp[0][i]=INF;  
    //Inicializando a primeira coluna  da matriz dp
    for(int i=0;i<100;i++) dp[i][0]=0;
    //Tabulacao da matriz dp
    for(int i=1;i<=n;i++){
        for(int j=1;j<w+1;j++){
            if(coins[i-1]<=j) dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    //A resposta eh o ultimo elemento tabulado
    cout << dp[n][w] << "\n";
  
}