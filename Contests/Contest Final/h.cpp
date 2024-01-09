#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
struct Node{
    int is_end_cnt=0;
    int dist;
    Node* ch[26];
    Node():dist(INF){
        memset(ch,0,sizeof(ch));
    }
};
Node* root;
void add(string s){
    Node* cur=root;
    int t=0;
    for (int i=0;i<s.size();i++){
        if(!cur->ch[s[i]-'a']) cur->ch[s[i]-'a']=new Node();
        cur->dist=min(cur->dist,(int)(s.size()-t++));
        cur=cur->ch[s[i]-'a'];
    }
    cur->is_end_cnt++;
}
int match(string s){
    Node* cur=root;
    for(int i=0;i<s.size();i++){
        if(!cur->ch[s[i]-'a']) return -1;
        cur=cur->ch[s[i]-'a'];
    }
    if(cur->is_end_cnt) return 0;
    return cur->dist;
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    root=new Node();
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        add(s);
    }
    for(int i=0;i<q;i++){
        string s;
        cin >> s;
        cout << match(s) << "\n";
    }
}