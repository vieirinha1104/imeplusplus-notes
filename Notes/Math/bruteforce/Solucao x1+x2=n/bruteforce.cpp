#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,x,y;
    vector<pair<int,int>> v;
    long long cnt=0;
    cin >> x >> y >> a >> b;
    for(int i=a;i<=x;i++){
        for(int j=b;j<=y;j++){
            if(i>j){
                pair<int,int> p;
                p.first=i;
                p.second=j;
                v.push_back(p);
                cnt++;
            }
        }
    }
    if(cnt==0){
        cout << cnt << "\n";
        return 0;
    }
    else{
        cout << cnt << "\n";
        for(int i=0;i<v.size();i++){
            cout << v[i].first << " " << v[i].second << "\n";

        }
            return 0;
    }
}