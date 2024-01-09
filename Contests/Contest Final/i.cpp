#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int arr[N];
// Exata a mesma logica do two sum, mas para achar o total de pares eh melhor usar lower bound e upper bound
// do que a solucao com map
int main(){
    int n,x;
    long long cnt=0;
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> arr[i];
    //Ordenada o vetor para ser valido: binary search, lower bound,upper bound,etc
    sort(arr,arr+n);
    //Vamos iterar pelo array
    //Como vamos sempre formar pares arr[i] com seus sucessores, arr[i+1] com seus sucessores
    //necessariamente vai formar pares distintos dos de arr[i]
    for(int i=0;i<n-1;i++){
        // Se arr[i] nao deixar resto zero, ele nao compoem nenhum dos dois membros de um dos pares da solucao
        if(x%arr[i]!=0) continue;
        int targ=x/arr[i];
        //Vamos ver se o par de arr[i] esta no array, e quantas vezes ele aparece: count = y-z
        long long y=upper_bound(arr+i+1,arr+n,m)-arr; //Index do primeiro elemento que eh >targ
        long long z=lower_bound(arr+i+1,arr+n,m)-arr; //Index do primeiro elemento que eh >=targ
        // y - z eh justamente a quantidade de vezes que o targ aparece no array
        cnt+=y-z;
    }
    cout << cnt << "\n";

}