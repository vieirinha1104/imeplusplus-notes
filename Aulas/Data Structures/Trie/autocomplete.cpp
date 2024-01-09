#include <bits/stdc++.h>
using namespace std;
// Basicamento: eh dado uma lista de palavras de um historico de usario
// Entao sao feitas varias queries de palavras 
// Retornar o numero de palavras distintas do historico que tem a string da query como prefixo
struct Node{
    int is_end_cnt=0;
    int cnt=0;
    Node* ch[26];
    Node(){
        memset(ch,0,sizeof(ch));
    }
};
Node* root;
void add(string s){
    Node* cur=root;
    for(auto c : s){
        if(!cur->ch[c-'a']) cur->ch[c-'a']=new Node();
        cur=cur->ch[c-'a'];
        cur->cnt++;
    }
    cur->is_end_cnt++;
}
int match(string s){
    Node* cur=root;
    for(auto c : s){
        if(!cur->ch[c-'a']) return 0;
        cur=cur->ch[c-'a'];
    }
    return cur->cnt;
}

int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    root=new Node();
    int n,m;
    cin >> n;
    set<string> ss;
    while(n--){
        string s;
        cin >> s;
        ss.insert(s);
    }
    for(auto it : ss) add(it);   
    cin >> m;
    for(int i=1;i<=m;i++){
        string s;
        cin >> s;
        cout << match(s) << "\n";
    }
    return 0;
}