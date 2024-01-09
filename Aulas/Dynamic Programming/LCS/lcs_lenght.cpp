#include <bits/stdc++.h>
using namespace std;
const int N = 3e3+5; 
//LCS: O(nm),onde n: size(s) e m: size(t)
int dp[N][N];
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    memset(dp,0,sizeof(dp));
    int n=s.size(),m=t.size();
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout << dp[0][0] << "\n";
}