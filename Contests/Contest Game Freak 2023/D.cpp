#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 108;
const ll INF = 1e18;
ll dp[N][100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int s=0;
    ll t_votes=0,a_votes=0;
    for(int i=0;i<n;i++){
       int a, b, c;
       cin >> a >> b >> c;
       s += c;
       if(b>a){
            a_votes+=c; v.push_back({(b-a+1)/2,c});
       }
       else t_votes+=c;
    }
    if(t_votes>a_votes) cout << 0 << "\n";
    else{
        memset(dp, 63, sizeof dp);
        for(int i=0;i<=v.size();i++){
            dp[i][0]=0; 
        }
        for(int i=1;i<=v.size();i++){
            for(int j=1;j<=s;j++){
                if(v[i-1].second<=j){
                    dp[i][j]=min(v[i-1].first+dp[i-1][j-v[i-1].second],dp[i-1][j]);
                    continue;
                } 
                dp[i][j]=dp[i-1][j];
            }
        }
        ll ans=INF;
        for(int i=(a_votes-t_votes+1)/2;i<=s;i++){
            ans=min(ans,dp[v.size()][i]);
        }
        cout << ans << "\n";
    }
    
}