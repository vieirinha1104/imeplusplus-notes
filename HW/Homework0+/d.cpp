#include <bits/stdc++.h>

using namespace std;

void inserction_sort(int *v,int tam){
for(int i=1;i<tam;i++){
    int aux=v[i];
    for(int j=i-1;j>=0;j--){
        if(v[j]<aux){
            v[j+1]=aux;
            break;
        }
        else{
            v[j+1]=v[j];
            if(j==0){
                v[0]=aux;
            }
        }
        }
}
}

int main(){
    int n,k;
    cin >> n >> k;
    int vector[50];
    for(int i=0;i<50;i++){
        vector[i]=1000000;
    }
    for(int i=0;i<k;i++){
        cin >> vector[i];
    }
    inserction_sort(vector,50);
    int ans=1000;
    for(int i=0;i<k-n+1;i++){
        if(vector[i+n-1]-vector[i]<ans){
            ans=vector[n+i-1]-vector[i];
        }
    }
    cout << ans << "\n";    

}