#include <bits/stdc++.h>

using namespace std;

int tania_dice(int n,int s,int r){
    int *v=(int*)malloc(n*sizeof(int));
    v[n-1]=s-r;
    for(int i=0;i<n-1;i++){
        v[i]=1;
    }
    int sum=0;
    int j=0;
    for(int i=0;i<n;i++){
            sum=sum+v[i];
        }
    while(1){
        if(j < n and sum<s && v[j]<s-r){
            v[j]++;
            j++;
            sum++;
        }
        else if(j==n-1){
            j=0;
        }
        else if(sum==s){
            break;
        }
    
    }
       for(int i=0;i<n;i++){
            cout << v[i] <<" ";
        }
        cout << "\n";
        return 0;

}
int main(){
   int t;
   cin >> t;
   for(int i=0;i<t;i++){
    int n,s,r;
    cin >> n >> s >> r;
    tania_dice(n,s,r);
   }
}