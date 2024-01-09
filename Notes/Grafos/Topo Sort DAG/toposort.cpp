#include <bits/stdc++.h>
#define N 1000000

using namespace std;
  vector<int> adj[N],inc(N),tsort;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int ans=0;
    queue<int> q;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b); inc[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!inc[i]) q.push(i);
    }
    while(!q.empty()){
        int x=q.front(); q.pop(); tsort.push_back(x);
        for(auto e : adj[x]){
            inc[e]--;
            if(!inc[e]) q.push(e);
        }
    }
        if(tsort.size()!=n) cout << "IMPOSSIBLE\n";
        for(int i=0;i<tsort.size();i++){
            if(i!=tsort.size()-1) cout << tsort[i] << " ";
            else cout << tsort[i] << "\n";
        }
    
}     

        
        
        
        
        
      