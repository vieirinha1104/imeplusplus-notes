#include <bits/stdc++.h>
using namespace std;
const int N = 2005,INF=1e9;
vector<pair<int,int>> v; //obj.st = weight, obj.nd = value
int dp[N][N];

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int w,n;
    cin >> w >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(v[i-1].first<=j) dp[i][j]=max(v[i-1].second+dp[i-1][j-v[i-1].first],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout << dp[n][w] << "\n";

}