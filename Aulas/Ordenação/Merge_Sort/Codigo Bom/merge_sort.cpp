#include <bits/stdc++.h>
#define N 1000005
using namespace std;


vector<int> merge_sort(vector<int> v){
    int n=v.size(); int mid=(n)/2; vector<int> ans;
    if(n==1) return v;
    vector<int> l,r;
    for(int i=0;i<mid;i++) l.push_back(v[i]);
    for(int i=mid;i<n;i++) r.push_back(v[i]);
    l=merge_sort(l); r=merge_sort(r);
    //Merge:
    int i=0,j=0;
    while(i<l.size() or j<r.size()){
        if(i>=l.size()) ans.push_back(r[j++]);
        else if(j>=r.size()) ans.push_back(l[i++]);
        else if(r[i]>=l[j]) ans.push_back(l[i++]);
        else ans.push_back(r[j++]); 
        //else ans.pb(r[pr++]), cnt += l.size() - pl; //inversion
    }
    return ans;
}

int main(){
    vector<int> v(10);
    for(int i=1;i<=10;i++){
        v[i-1]=11-i;
    }    
    vector<int> ans=merge_sort(v);
    for(int i=0;i<10;i++){
        cout << ans[i] << " ";
    }
}