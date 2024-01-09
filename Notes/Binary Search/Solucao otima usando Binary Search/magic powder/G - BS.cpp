#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long arr[N],brr[N],n,mp;

bool check(int k){
    long long mp_needed=0;
    for(int i=0;i<n;i++){
        if((brr[i]-k*arr[i])<0) mp_needed+=k*arr[i]-brr[i];
        if(mp_needed>mp) return false; //avoid overflow
    } 
    return mp_needed<=mp;
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >> n >> mp;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++) cin >> brr[i];
    long long l=0,r=2e9;
    while(l<r){
        long long m=(l+r+1)/2;
        if(check(m)) l=m;
        else r=m-1;
    }
    cout << l << "\n";
}
