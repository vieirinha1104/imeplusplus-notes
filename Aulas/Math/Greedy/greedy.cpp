#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    if(n>=m){
        cout << (n-m) << "\n";
        return 0;
    }
    else{
        int aux=m;
        int cnt=0;
        while(aux>n){
            if(aux%2==1){
                aux+=1;
                cnt++;
            }
            else{
                aux/=2;
                cnt++;
            }
        }
        if(aux==n){
            cout << cnt << "\n";
            return 0;
        }
        else{
            cout << (cnt+(n-aux)) << "\n";
            return 0;
        }
    }
}