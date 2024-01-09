#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    int vector[100];
    for(int i=0;i<n;i++){
        cin >> vector[i];
    }
    pair<int,int> p[100];
    for(int i=0;i<n;i++){
        p[i].first=i+1;
        p[i].second=vector[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;i<n;i++){
            if(p[j].second==(i+1)){
                cout << p[j].first<<" ";
                break;
            }
        }
    }
}