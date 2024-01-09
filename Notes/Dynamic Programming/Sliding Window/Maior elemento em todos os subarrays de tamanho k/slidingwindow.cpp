#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> arr;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int> ms;
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ms.insert(nums[i]);
    }
    ans.push_back(*ms.rbegin());
    for (int i = k; i < (int)nums.size(); i++) {
        ms.erase(ms.find(nums[i - k]));
        ms.insert(nums[i]);
        ans.push_back(*ms.rbegin());
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> ans;
    ans=maxSlidingWindow(v,2);
    for(auto x : ans) cout << x << " ";

    
}