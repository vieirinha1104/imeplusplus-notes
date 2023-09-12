
#include <bits/stdc++.h>

using namespace std;
bool check_color(vector<int> adj,char color,vector<char> cores){
    for(int i=0;i<adj.size();i++){
        if(cores[adj[i]]=='\0'){
            break;
        }
        if(color==cores[adj[i]]){
            return false;
        }
    }
    return true;
}
void backtracking(vector<int> adj[],vector<char> &s,int k){
    if(k==5){
        for(int i=0;i<5;i++){
            cout << s[i] << " ";
        }
        cout <<"\n";
    }
    else{
        for(char i='a';i<='c';i++){
            char x = s[k];
            s[k]=i;
            if(check_color(adj[k],s[k],s)){
                backtracking(adj,s,k+1);
            }
            else{
                continue;
            }
        }
    }
    }

int main(){
    vector<int> adj[5];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[0].push_back(4);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(4);

    adj[3].push_back(0);
    adj[3].push_back(1);

    adj[4].push_back(0);
    adj[4].push_back(2);
    
    vector<char> cores(5);
    backtracking(adj,cores,0);
  
}