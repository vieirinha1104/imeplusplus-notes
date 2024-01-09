#include <bits/stdc++.h>
using namespace std;
// [ -1 2 4 5 -4 -11 9 12]
const int N=2e5+5;
int arr[N];
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    long long ans=0,cur=0;
    for(int i=0;i<n;i++){
        cur+=arr[i];
        if(cur<0) cur=0;
        ans=max(cur,ans);
    }
    if(!ans){
        sort(arr,arr+n);
        cout << arr[n-1] << "\n";
        return 0;
    }
    cout << ans << "\n";
}