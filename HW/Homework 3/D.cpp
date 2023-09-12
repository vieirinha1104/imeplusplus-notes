#include <bits/stdc++.h>
using namespace std;

pair<int,int> moves[8];
int t;

struct node{
    int col,row; int vis=0; int level=1;
    vector<node*> children;
    node(int r,int c):col(c),row(r){};
    node(){};
};

bool check(int c,int r){
    if(c>=0 and c<8 and r>=0 and r<8) return true;
    else return false;
}

void bfs(node* root,pair<int,int> goal,int i) {
   root->vis=1;
   for(int i=0;i<8;i++){
        int u=(root->row)+moves[i].first;int v=(root->col)+moves[i].second;
        if(check(u,v)){
            node* tmp=new node(u,v);
            tmp->level=2;
            (root->children).push_back(tmp);
        }
    }
   queue<node*> q; q.push(root);
   while (!q.empty()) {
       node* u = q.front(); q.pop();
       for (auto x : u->children){
            if(!(x->vis)){ 
                x->vis=1;
                if(x->row==goal.first and x->col==goal.second){
                    cout << x->level-1;
                    if(i<t){
                        cout <<"\n";
                    }
                    return;
                }
                for(int i=0;i<8;i++){
                    int u=(x->row)+moves[i].first;int v=(x->col)+moves[i].second;
                    if(check(u,v)){
                        node* tmp=new node(u,v);
                        tmp->level=x->level+1;
                        (x->children).push_back(tmp);
                    }
                }
                q.push(x);
            }   
        }
    }
}

int main(){
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   moves[0]={1,2}; moves[1]={2,1}; moves[2]={-1,-2}; moves[3]={-2,-1}; moves[4]={-2,1}; moves[5]={1,-2}; moves[6]={2,-1}; moves[7]={-1,2};
   cin >> t;
   for(int i=0;i<t;i++){
    string s1,s2; int n,m; pair<int,int> goal;
    cin >> s1 >> s2;
    n=s1[0]-97; m=s1[1]-49; goal.first=s2[0]-97; goal.second=s2[1]-49;
    if(n==goal.first and m==goal.second){
        cout<<0;
        if(i<t){
            cout <<"\n";
        }
    }
    else{
        vector<node*> tree(1); tree[0]=new node(n,m);
        bfs(tree[0],goal,i);
    }
   }
   return 0;
   

   
}