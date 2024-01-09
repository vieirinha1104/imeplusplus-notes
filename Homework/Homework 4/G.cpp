#include <bits/stdc++.h>
#define N 1000000
using namespace std;

int par[N + 1],sz[N + 1],ans;
int find(int a){
    return par[a]==a ? a : par[a]=find(par[a]);
}
void unite(int a,int b){
    int x= find(a); int y=find(b);
    if(x==y) return;
    if(sz[x]>sz[y]) swap(x,y);
    sz[y]+=sz[x]; 
    ans--;
    par[x]=y; //Ligar sempre o menor no maior, para melhorar a complexidade
}
int main(){
    int t;
    scanf("%d",&t);
    bool first = true;
    char s[5];
    scanf(" %s", s);
    while(t--) {
        if(first) {
            printf("\n");
            first = false;
        }
        ans=s[0]-'A'+1;
        for(int i=1;i<=N;i++){
            sz[i]=1; par[i]=i;
        }
        while(scanf(" %s", s) != EOF && strlen(s) == 2){
            unite(s[0]-'A'+1,s[1]-'A'+1);
        }
        printf("%d\n", ans);
    }
}
