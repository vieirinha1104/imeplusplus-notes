#include <bits/stdc++.h>

using namespace std;

{
int main()
   int n,x,a;
   bool cmp;
   cin >> n >> x;
   vector<int> v;
   for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
   }
   vector<int>::iterator it=v.begin();
   for(int i=0;i<n;i++){
        if(x%v[i]!=0){
            continue;
        }
        int aux=(x/arr[i]);
        while(cmp==true){
        cmp=binary_search(it,v.end(),aux);
        if(cmp==true){
            vector<int>::iterator tmp=it;
            it=lower_bound(tmp,v.end(),aux);
            it++;
        }
        else{
            continue;
        }
        }
   }

}