#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> adj[N],inc(N),tsort;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int ans=0;
    priority_queue<int> pq;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b); inc[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!inc[i]) pq.push(-i);
    }
    while(!pq.empty()){
        int x=pq.top(); pq.pop(); tsort.push_back(-x);
        for(auto e : adj[-x]){
            inc[e]--;
            if(!inc[e]) pq.push(-e);
        }
    }
        if(tsort.size()!=n){
            cout << "Sandro fails.";
            return 0;
        } 
        //Se nao tiver esse " " o ultimo elemento do tsort vai dar WA
        for(int i=0;i<tsort.size();i++) cout << tsort[i] << " ";
    
}     

        
        
        
        
        
      