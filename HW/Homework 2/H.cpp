#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<vector<int>> ans(6, vector<int>(3));
    ans[0][1]=1;
    ans[0][2]=2;
    for(int i=1;i<6;i++){
        ans[i]=ans[i-1];
        if(i%2==1){
            swap(ans[i][0],ans[i][1]);
        }
        else{
            swap(ans[i][1],ans[i][2]);
        }
    }
    long long n;
    int x;
    cin >> n >> x;
    long long aux=n%6;
    cout << ans[aux][x] << "\n";


}