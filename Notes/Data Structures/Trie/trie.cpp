#include <bits/stdc++.h>
using namespace std;
struct Node{
    int cnt=0;
    int is_end_cnt=0;
    Node* ch[26];
    Node():cnt(0){
        memset(ch,0,sizeof(ch));
    }
};
Node* root;
void add(string s){
    Node* cur=root;
    cur->cnt++;
    for(auto c : s){
        if(!cur->ch[c-'a']) cur->ch[c-'a']=new Node();
        cur=cur->ch[c-'a'];
        cur->cnt++;
    }
    cur->is_end_cnt++;
}
int match(string s) {
    Node* cur=root;
    for(auto c : s){
        if(!cur->ch[c-'a']) return false;
        cur = cur->ch[c-'a'];
    }
    if(!cur->is_end_cnt) return false; // If you only need to count prefixes (not
    // the exact word), comment this line
    // if you need to count prefixes
    // return cur->cnt;
    return cur->is_end_cnt;
}
int main(){
    cin.tie(NULL);
	ios_base::sync_with_stdio(false); 
    root=new Node();   
}