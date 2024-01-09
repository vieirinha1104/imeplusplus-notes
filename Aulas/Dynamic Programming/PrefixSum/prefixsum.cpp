#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> arr(N);
vector<int> ps;

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ps.push_back(0);
    for(int i=1;i<=n;i++){
        ps.push_back(ps[i-1]+arr[i-1]);
    }
    for(auto x : ps) cout << x << " ";
}