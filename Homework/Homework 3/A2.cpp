#include <bits/stdc++.h>
using namespace std;
int n,m;
//Solucao por teoria de grafos,usando BFS, mas montei a arvore fznd aloc dinamica, tive problemas com Memory Limit Exceed
bool check(int c){
    if(c>=0) return true;
    else return false;
}
struct node{
    int curl; int vis=0; int level=1;
    vector<node*> children;
    node(int key):curl(key){};
    node(){};
    ~node(){};
};
void bfs(node* root) {
   root->vis=1;
   for(int i=0;i<2;i++){
        if(!i){
            int u=(root->curl)*2;
            node* tmp= new node(u);
            tmp->level=2;
            (root->children).push_back(tmp);
        }
        else{
            int u=(root->curl)-1;
            if(check(u)){
            node* tmp= new node(u);
            tmp->level=2;
            (root->children).push_back(tmp);
            }
        }
    }
   queue<node*> q; q.push(root);
   while (!q.empty()) {
       node* u = q.front(); q.pop();
       for (auto x : u->children){
            if(!(x->vis)){ 
                x->vis=1;
                if((x->curl)==m){
                    cout << x->level-1 << "\n";
                    return;
                }
                for(int i=0;i<2;i++){
                    if(!i){
                        int u=(x->curl)*2;
                        node* tmp= new node(u);
                        tmp->level=(x->level)+1;
                        (x->children).push_back(tmp);
                    }
                    else{
                        int u=(x->curl)-1;
                        if(check(u)){
                        node* tmp= new node(u);
                        tmp->level=(x->level)+1;
                        (x->children).push_back(tmp);
                        }
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
    cin >> n >> m; 
    if(n>=m){
        cout << (n-m)<<"\n";
        return 0;
    }
    else{
        vector<node*> tree(1); tree[0]=new node(n);
        bfs(tree[0]);    
    }
}