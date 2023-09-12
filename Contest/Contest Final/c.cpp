#include <bits/stdc++.h>

using namespace std;
int main(){
    long long t,n,a;
    scanf("%lld",&t);
    for(long long i=0;i<t;i++){
        scanf("%lld",&n);
        long long sum=0;
        long long cnt=0;
        set<long long> s;
        for(long long i=0;i<n;i++){
            scanf("%lld",&a);
            s.insert(a);
            if(n==1){
            printf("1 %lld\n",a);
            }
        }
        if(n==1){
            continue;
        }
        long long k=s.size();
        for(long long i=0;i<k+1;i++){
            if(s.size()==0){
                    break;
                }
            auto itr=s.begin();
            long long v=*(itr);
            if(v>sum){
                s.erase(v);
                cnt++;
                sum+=v;
                if(s.size()==0){
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                s.erase(v);
            }
        }
        printf("%lld %lld\n",cnt,sum);
    }
    return 0;
}
