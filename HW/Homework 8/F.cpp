#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int pag[1005],price[1005];
int dp[1005][N];
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> price[i];
    for(int i=0;i<n;i++) cin >> pag[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(price[i-1]<=j) dp[i][j]=max(pag[i-1]+dp[i-1][j-price[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout << dp[n][x] << "\n";
}