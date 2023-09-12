#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    map< pair<int,int>,string> m;
    int c,d;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c >> d >> s;
        m[{c,d}]=s;
    }
    int t;
    int a,b;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b;
        cout << m[{a,b}] << "\n";

    }

}