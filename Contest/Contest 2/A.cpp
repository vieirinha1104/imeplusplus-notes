#include <bits/stdc++.h>
#define N 1000005
using namespace std;
long long inv;

vector<int> merge_sort(vector<int> &v){
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
        else if(r[j]>=l[i]) ans.push_back(l[i++]);
        else ans.push_back(r[j++]),inv+=l.size()-i; 
        //else ans.pb(r[pr++]), cnt += l.size() - pl; //inversion
    }
    return ans;
}

int main(){
    int t,n; vector<int> v;
    cin >> t;
    for(int i=0;i<t;i++){
        inv=0;
        cin >> n;
        for(int j=0;j<n;j++){
            int x; cin >> x;
            v.push_back(x);
        }
        v=merge_sort(v);
        cout << inv << "\n";
        v.clear();
        inv=0;
    }
}