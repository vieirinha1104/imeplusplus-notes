#include <bits/stdc++.h>

using namespace std;

int recursiva(long long n){
    if(n==0){
        return 1;
    }
    else if(n==1){
        return 8;
    }
    else{
        if(n%2==0){
           return( (recursiva(n/2)*recursiva(n/2)) % 10);
        }
        else{
            return ((1378*recursiva(n-1))%10);
        }
    }

}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    set<long long> s;
    s.insert(1);
    s.insert(2);
    s.erase(1);
    auto itr =s.begin();
    long long b=*(itr);
    cout << b;

}