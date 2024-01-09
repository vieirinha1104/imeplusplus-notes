#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5,INF=1e9;
vector<int> arr(N);
int dp[N];
//Um sapo se inicia na pedra 1, ele pode pular da pedra i para i+1 ou i+2 ou ... i+k
//Cada vez que ele pula da pedra i para j, ha um custo abs(arr[i]-arr[j])
//Qual custo minimo para chegar na pedra N ?
//Ideia para montar a recorrencia: dado que o sapo chegou na pedra N, ele pulou da N-1 ou N-2 ou N-3 ... ou N-K
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int min=INF;
        for(int j=i-1;j>=i-k;j--){
            if(j<1) break;
            int x=dp[j]+abs(arr[i]-arr[j]);
            if(min>x) min=x;
        }
        dp[i]=min;
    }
    cout << dp[n] << "\n";
}