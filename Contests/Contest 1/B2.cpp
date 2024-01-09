#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long arr[N];
int main(){
    int n,x;
    int pos1=-1,pos2=-1;
    cin >> n >> x;
    for(int i=1;i<=n;i++) cin >> arr[i];
    unordered_map<long long,int> m;
    for(int i=1;i<=n;i++){
        if(m.find(x-arr[i])==m.end()){ 
            if(m.find(arr[i])==m.end()) m[arr[i]]=i;
        }
        else{
            pos1=i;
            pos2=m[x-arr[i]];
        }
    }
    if(pos2==-1) cout << -1 << "\n";
    else cout << pos1 << " " << pos2 << "\n";

}