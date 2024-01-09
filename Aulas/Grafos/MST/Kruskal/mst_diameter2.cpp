#include <bits/stdc++.h>
#define N 100005
using namespace std;

int par[N],sz[N],vis[N],dis[N];
vector<int> adj[N];
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
bool unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return true;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x];
    par[x]=y; //Ligar sempre o menor no maior, para melhorar a complexidade
    return false;
}
void bfs(int a){
	memset(vis, 0, sizeof (vis)); memset(dis, 0, sizeof (dis));
	queue<int> q; q.push(a);
	while(!q.empty()){	
        int b = q.front();
		q.pop(); vis[b] = 1; 
		for(int i = 0 ; i < adj[b].size() ; i++){
			int c = adj[b][i];
			if(vis[c] == 0) {
				dis[c] = dis[b] + 1;
				q.push(c); 
			}
		}
	}
}
int main(){
    //MST:
    int n,m; long long ans=0;
    vector<pair<long long,pair<int,int>>> edges;
    for(int i=1;i<N;i++){
        par[i]=i; sz[i]=1;
    }
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; long long c;
        cin >> a >> b >> c;
        pair<long long,pair<int,int>> p;
        p.first=c; p.second.first=a; p.second.second=b;
        edges.push_back(p);
    }
    sort(edges.begin(),edges.end());
    for( auto e : edges ){
        int x= find(e.second.first); int y=find(e.second.second);
        if(unite(x,y)) continue;
        else{
            ans+=e.first;
            adj[e.second.first].push_back(e.second.second); adj[e.second.second].push_back(e.second.first);
        }
    }
    //Diametro:
    bfs(1);
	int greater=-1,v=-1;
	for(int i =1;i<= n;i++){
		if(dis[i]>greater){          
			greater = dis[i]; 
			v=i;           
		}
	}
	bfs(v);
	int u=-1,d=-1;
    for(int i = 1 ; i <= n ; i++){
		if(dis[i]>d) d = dis[i];
	}
    cout << ans << "\n" << d << "\n";
}