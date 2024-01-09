#include <bits/stdc++.h>

using namespace std;
int main(){
    int t;
    string s;
    string ans;
    string s1;
    string s2;
    int cnt;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> s1 >> s2;
        ans=s1+s2;
        sort(ans.begin(),ans.end());
        cout << ans << "\n";
    }
}