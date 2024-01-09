#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    int arr[2000];
    int t=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
       for(int j=i+1;j<n;j++){
        int c=(arr[i]+arr[j]);
        auto itr=lower_bound(arr,arr+n,c);
        t+=((itr-arr-1)-j);
       }
    }
    cout << t << "\n";

    }
