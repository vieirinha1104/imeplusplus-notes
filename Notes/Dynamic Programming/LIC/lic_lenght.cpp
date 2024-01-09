#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int dp[N][N],arr[N];
vector<int> v;
//Problema: Dado um array achar o LIC dele
//Ideia: Montar um vector v que contem todos os elementos de arr ordenados e sem repeticao(set)
//LIC de arr vai ser o LCS(v,arr). Desvantagem: o algoritmo fica O(n^2), mas ha algoritmo melhor em O(nlogn)
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    set<int> s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    for(auto x : s) v.push_back(x);
    memset(dp,0,sizeof(dp)); 
    for(int i=v.size()-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(v[i]==arr[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout << dp[0][0] << "\n";
}