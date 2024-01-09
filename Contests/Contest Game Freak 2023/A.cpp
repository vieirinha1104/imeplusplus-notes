#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,h,x;
    vector<int> p;
    cin >> n >> h >> x;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        p.push_back(k);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int aux=h;
        aux+=p[i];
        if(aux>=x){
            ans=i+1;
            break;
        }
    }
    cout << ans << "\n";
}