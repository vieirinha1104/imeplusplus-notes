#include <bits/stdc++.h>

using namespace std;

long long fastexp(long long a,long long b, long long c){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a%c;
    }
    else{
        if(b%2==0){
            long long aux=fastexp(a,b/2,c);
            return (aux*aux) % c;
        }
        else{
            return ( (a%c)*fastexp(a,b-1,c) ) % c;
            }
        }
}

int main(){
    int k;
    long long ans;
    int i;
    cin >> k;
    for(i=k-1;i>=0;i--){
        long long a,b,c;
        cin >> a >> b >> c;
        ans=fastexp(a,b,c);
        cout << ans << "\n";
    }
    cin >> i;
    
}