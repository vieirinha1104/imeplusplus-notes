#include <bits/stdc++.h>

using namespace std;

int main(){
    set<long long> s;
    int n;
    string key;
    string aux = "1";
    long long t,cnt = 0;
    cin >> n;
    for(int i=0;i<n;i++){
    cin >> key >> t;
    if(key[0]=='+' && aux[0]!='?'){
        s.insert(t);
        aux[0]=key[0];
    }
    else if(key[0]=='?'){
        auto itr = s.lower_bound(t);
        if(itr==s.end()){
            cout << -1 << "\n";
            cnt = -1;
            aux[0]='?';
        }
        else{
            cnt = *itr;
            cout << cnt <<"\n";
            aux[0]='?';
        }
    }
    else if(key[0]=='+' && aux[0]=='?'){
        s.insert((t+cnt)%(1000000000));
    }
    }
    }
