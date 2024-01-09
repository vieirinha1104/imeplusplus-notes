#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int arr[N],brr[N],n,mp;
// Vamos fazer uma solucao bruteforce, vamos tentar fazer 0 biscoitos, se tiver-mos ingrediente para isso
// Entao tentaremos fazer 1 biscoito:
// 1-) Se tivermos ingrediente para fazer 1 biscoito, vamos tentar fazer 2 biscoitos
// 2-) Se nao tivermmos ingredientes para fazer 1 biscoito, nossa resposta sera 0
bool check(int k){
    int mp_needed=0;
    for(int i=0;i<n;i++){
        if((brr[i]-k*arr[i])<0) mp_needed+=k*arr[i]-brr[i];
    } 
    return mp_needed<=mp;
}

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >> n >> mp;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++) cin >> brr[i];
    int ans=0;
    while(check(ans)){
        ans++;
    }
    cout << ans-1 << "\n";
}