#include <bits/stdc++.h>

using namespace std;

int adj[100][100];
vector<int> dist;

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            adj[i][j]=-1;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a][b]=c;
        adj[b][a]=c;
    }
    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }
    do {
        dist.push_back(0);
        for(int j=0;j<n-1;j++){
            int w=adj[perm[j]][perm[j+1]];
            if(w==-1) break;
            dist[dist.size()-1]+=w;
        }

    } while(next_permutation(perm.begin(), perm.end()));
    sort(dist.begin(),dist.end());
    cout << dist[dist.size()-1];
}