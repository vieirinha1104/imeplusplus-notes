#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ans;
set<int> s;

bool prime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

bool check(int x,int k){
    if(k==n-1){
        if(prime(ans[n-1]+ans[0]) and prime(ans[n-1]+ans[n-2])){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(prime(ans[k]+ans[k-1])){
            return true;
        }
        else{
            return false;
        }
    }
}
void backtracking(int k){
    if(k==n){
        for(int i=0;i<n;i++){
            if(i==n-1){
                cout << ans[i] << "\n";
    //Se voce printar espaco apos o ultimo elemento, vai dar presentation error
             }
            else{
            cout << ans[i] << " ";
            }       
        }
    }
    else{
        for(int i=2;i<=n;i++){
            if(s.find(i)==s.end()){
                continue;
            }
            else{
                ans.push_back(i);
                s.erase(i);
                if(check(ans[k],k)){
                    backtracking(k+1);
                    s.insert(i);
                    ans.pop_back();
                }
                else{
                    s.insert(i);
                    ans.pop_back();
                    continue;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(cin >> n){
        if(t != 1){
            cout<<"\n";
        }
        ans.clear(); s.clear();
        for(int i=2;i<=n;i++){
            s.insert(i);
        }
        ans.push_back(1);
        cout << "Case " << t << ":\n";
        backtracking(1);
        t++;
    }


}