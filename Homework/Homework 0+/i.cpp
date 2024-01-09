#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int tam= s.size();
    long long answ=0;
    long long aux=1;
    for(int i=tam-1;i>=0;i--){
       answ=answ+(s[i]-64)*aux;
       aux=aux*26;
    }
    cout << answ << "\n";
    
}