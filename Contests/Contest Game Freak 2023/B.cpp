#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        if(!binary_search(v.begin()+i+1,v.end(),v[i]+1)){
            ans=v[i]+1;
            break;
        }
    }
    if(ans==0){
        ans=v[0]-1;
    }
    cout << ans << "\n";
}