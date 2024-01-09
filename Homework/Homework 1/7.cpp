#include <bits/stdc++.h>

using namespace std;

void busca_binaria(long long *v,int tam,long long key){
    int i=0;
    int f=tam-1;
    int m=(i+f)/2;
    while(i<f){
        m=(i+f)/2;
        if(v[m]==key){
            i=m;
            break;
        }
        else if(v[m]<key){
            i=m+1;
        }
        else{
            f=m-1;
        }
    }
    if(v[i]==key){
        while(v[i]==key && i>=0){
            i--;
        }
        cout << i+1 << "\n";
        return;
    }
    else{
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
       busca_binaria(arr,n,key);
    }
}