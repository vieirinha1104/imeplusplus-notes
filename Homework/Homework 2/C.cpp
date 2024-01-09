#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<pair<int,int>> v;
    cin >> n;
    set<pair<int,int>> s;
    int answ=0;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        int a,b;
        cin >> a >> b;
        p.first=a;
        p.second=b;
        v.push_back(p);
        s.insert(p);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            pair<int,int> p1;
            pair<int,int> p2;
            pair<int,int> p3;
            p1.first=v[i].first;
            p1.second=v[i].second;
            p2.first=v[j].first;
            p2.second=v[j].second;
            if((p1.first+p2.first)%2!=0||(p1.second+p2.second)%2!=0){
                continue;
            }
            else{
                p3.first=((p1.first)+(p2.first))/2;
                p3.second=((p1.second)+(p2.second))/2;
                if(s.count(p3)){
                    answ++;
                }
                else{
                    continue;
                }
            }
        }
    }
    cout <<  answ << "\n";
}