#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> arr(N);
int dp[N];
//Um sapo se inicia na pedra 1, ele pode pular da pedra i para i+1 ou i+2
//Cada vez que ele pula da pedra i para j, ha um custo abs(arr[i]-arr[j])
//Qual custo minimo para chegar na pedra N ?
//Ideia para montar a recorrencia: dado que o sapo chegou na pedra N, ele pulou da N-1 ou N-2
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1]=0;
    dp[2]=abs(arr[2]-arr[1]);
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout << dp[n] << "\n";
}