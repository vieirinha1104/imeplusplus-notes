#include <bits/stdc++.h>
using namespace std;
const int N = 3e3+5; 
int dp[N][N];
string s,t;
string recover(int l,int c){
    string ans;
    if(l==s.size() or c==t.size()) return ans;
    if(s[l]==t[c]) ans+=(s[l]+recover(l+1,c+1));
    else{
        if(dp[l][c+1]>=dp[l+1][c]) ans+=recover(l,c+1);
        else ans+=recover(l+1,c);
    }
    return ans;
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >> s >> t;
    memset(dp,0,sizeof(dp));
    int n=s.size(),m=t.size();
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    string ans=recover(0,0);
    cout << ans << "\n";
}