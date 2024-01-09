#include <bits/stdc++.h>
#define INF 1e9

using namespace std;
typedef long long ll;

bool vis[25][25];
vector<int> dx,dy;
int h,w;
bool check=true;
int cnt=0;

void set_vis(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            vis[i][j]=false;
        }
    }
}

bool check_adj(int x,int y){
    if(x>=0 and x<h and y>=0 and y<w and !vis[x][y]) return true;
    return false;
}

int dfs(int l,int c){
    int cnt=1;
    vis[l][c]=true;
    if(check_adj(l,c+dx[l])) cnt+=dfs(l,c+dx[l]);
    if(check_adj(l+dy[c],c)) cnt+=dfs(l+dy[c],c);
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w;
    for(int i=0;i<h;i++){
        char c;
        cin >> c;
        if(c=='>') dx.push_back(1);
        else if(c=='<') dx.push_back(-1);
    }
    for(int i=0;i<w;i++){
        char c;
        cin >> c;
        if(c=='^') dy.push_back(-1);
        else if(c=='v') dy.push_back(1);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            set_vis();
            if(dfs(i,j)<h*w){ 
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    
}