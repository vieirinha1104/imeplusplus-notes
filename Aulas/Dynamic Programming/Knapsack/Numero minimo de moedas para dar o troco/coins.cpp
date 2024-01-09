#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5,INF=1e9;
int dp[105][N];
vector<int> coins;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,change;
    cin >> n >> change;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }
    memset(dp,63,sizeof(dp));
    for(int i=0;i<105;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=change;j++){
            if(coins[i-1]<=j) dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][change]>INF) cout << "-1\n";
    else cout << dp[n][change] << "\n";

}