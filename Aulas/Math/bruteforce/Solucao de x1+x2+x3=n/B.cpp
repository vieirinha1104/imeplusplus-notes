#include <bits/stdc++.h>

using namespace std;

int n,a,b,c;

int main(){
    cin >> n >> a >> b >> c;
    vector<int> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    vector<int> curl(3);
    int ans=0;
    sort(arr.begin(),arr.end());
    int k1,k2,k3;
    k1=n/arr[0];
    k2=n/arr[1];
   for(int i=k1;i>=0;i--){
    for(int j=0;j<=k2;j++){
        if(i*arr[0]+j*arr[1]>n){
            break;
        }
        int aux=i*arr[0]+j*arr[1];
        if((n-aux)%arr[2]!=0){
            continue;
        }
        else{
            curl[0]=i;
            curl[1]=j;
            curl[2]=(n-aux)/arr[2];
            if(ans<curl[0]+curl[1]+curl[2]){
                ans=curl[0]+curl[1]+curl[2];
            }
            
        }
    }
   }
   cout << ans << "\n";

}