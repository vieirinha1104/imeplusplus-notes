#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5; 
int dp[N][N];
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    int n=s.size(),m=t.size();
    //dp[i][j]=LCS(s[i,n],t[j,m])
    //Caso base: se s for vazio, aka. i=s.size(), dp[s.size()][j]=t.size()-j
    for(int i=s.size();i>=0;i--) dp[i][t.size()]=s.size()-i;
    for(int j=t.size();j>=0;j--) dp[s.size()][j]=t.size()-j;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]) dp[i][j]=dp[i+1][j+1]; //Se S[i]=T[j], nao precisa fzr nenhum mov
            else dp[i][j]=min(min(1+dp[i][j+1],1+dp[i+1][j]),1+dp[i+1][j+1]); 
        }
    }
    cout << dp[0][0] << "\n";
}