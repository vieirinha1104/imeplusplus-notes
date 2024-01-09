#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int v[N];
 
int main(){ 
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    int key,pos;
    cin >> key;
    sort(v,v+n);
    int l=0,r=n-1;
    while(l<r){
       int m=(l+r+1)/2;
       if(v[m]==key){
           l=m;
           break;
        }
       else if(v[m]<key) l=m;
       else r=m-1;
    }
   if(v[l]==key) pos=l;
   else pos=-1;
   cout << pos << "\n";
}