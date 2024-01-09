#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
// Valor a ser pago: P, Valor recebido: PG, Troco: W= PG - P
// Voce tem disponivel uma quantidade qtd[coins[i]] de moedas de coins[i] reais
// Determine o numero de moedas necessarias para dar o troco
vector<int> coins,qtd(N),sol;
int w,n;
bool check(int value,int pos){
    value+=(coins[pos]*sol[pos]);
    if(value<=w) return true;
    return false;
}
void backtracking(int k,int value,int ans){
    if(k==coins.size()){
        if(value==w) cout << ans << "\n";
        return;
    }
    for(int j=0;j<=qtd[coins[k]];j++){
        int aux=sol[k];
        sol[k]=j;
        if(check(value,k)) backtracking(k+1,(value+(j*coins[k])),ans+j);
        sol[k]=aux;
    }
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    int pg,p;
    cin >> pg >> p;
    w=pg-p;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        coins.push_back(x);
        sol.push_back(0);
    }  
    for(int i=0;i<n;i++){
        cin >> qtd[coins[i]];
    }  
    backtracking(0,0,0);
}