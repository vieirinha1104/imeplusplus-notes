#include <bits/stdc++.h>

using namespace std;

/*
void comparar_string(string a,string b){
    int x=a.size();
    int y=b.size();
    int m;
    int z;

    if(x<=y){
    m=x;
    z=0;
}
    else{
    m=y;
    z=1;
}
    int aux=0;
    for(int i=0;i<m;i++){
        int p=a[i];
        int q=b[i];
        if(p<q){
            cout << a;
            aux++;
            break;
        }
        else if(p>q){
            cout << b;
            aux++;
            break;
        }
    }
    if(aux==0 && z==0){
        cout << b;
    }
    else if(aux==0 && z==1){
        cout << a;
    }

}
*/

int main(){
    int n,k;
    cin >> n >> k;
    string a[n];
    string aux;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    //Ordenar (Bubble Sort)
    for(int i=1;i<k;i++){
    for(int i=0;i<k-1;i++){
        if(a[i]>a[i+1]){
            aux=a[i];
            a[i]=a[i+1];
            a[i+1]=aux;
        }
    }
    }
    //Printar
    for(int i=0;i<k;i++){
        cout << a[i] << "\n";
    }



}