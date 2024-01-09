#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const long long INF=1e18+5;
vector<long long> arr(N),ps;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++) cin >> arr[i];
    ps.push_back(0);
    for(int i=1;i<=n;i++) ps.push_back(ps[i-1]+arr[i-1]);
    long long ans=-INF;
    for(int i=k;i<=n;i++) ans=max(ans,ps[i]-ps[i-k]);
    cout << ans << "\n";
}