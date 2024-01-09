#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;
vector<int> vis(100);

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<v.size();i++){
        if(!vis[i] and (v[i].first == v[u].first or v[i].second == v[u].second)){
            dfs(i);
        }
    }
}

int main(){
    int n;
    int cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0;i<v.size();i++){
        if(!vis[i]){
        dfs(i);
        cnt++;
        }
    }
    cout << cnt-1 <<"\n";
  
    
    
}