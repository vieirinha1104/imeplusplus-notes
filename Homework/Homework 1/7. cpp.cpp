#include <bits/stdc++.h>

using namespace std;

void busca_binaria(long long *v,int inicio,int fim, long long valor){
    int mid= (inicio+fim+1)/2;
    if(v[mid-1]==valor){
        cout << (mid-1) << "\n";
        return;
    }
    else if(v[mid-1]>valor){
        busca_binaria(v,inicio,mid-1,valor);
    }
    else if(v[mid-1]<valor){
        busca_binaria(v,mid,fim,valor);
    }
    else {
          cout << -1 << "\n";
        return;
    }
    }


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    long long key;
    long long arr[100000];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<m;i++){
        cin >> key;
       busca_binaria(arr,0,n-1,key);
    }
}