#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int par[N + 1]; int sz[N + 1];
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
void unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x]; 
    par[x]=y; //Ligar sempre o menor no maior, para melhorar a complexidade
}
int main(){
   int t,n;
   map<string,int> m;
   cin >> t;
   for(int i=0;i<t;i++){
        cin >> n;
        int k=1;
        for(int i=1;i<=N;i++){
            par[i]=i; sz[i]=1;
        }
        for(int i=0;i<n;i++){
            string a,b;
            cin >> a >> b;
            if(a==b) continue;
            if(m.find(a)==m.end()) m.insert({a,k});
            k++;
            if(m.find(b)==m.end()) m.insert({b,k}); 
            k++;
            unite(m[a],m[b]); int x=find(m[a]);
            cout << sz[x] << "\n";
        }
   }
}
