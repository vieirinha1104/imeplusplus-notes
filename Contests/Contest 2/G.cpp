#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    if(a>b){
        cout <<"Takahashi\n";
    }
    else if(a<b){
        cout << "Aoki\n";
    }
    else{
        if(c==0){
            cout << "Aoki\n";
        }
        else{  
        cout <<"Takahashi\n";
        }
        return 0;
    }
}