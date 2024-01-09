#include <bits/stdc++.h>

using namespace std;
int main(){
    double t,x,y,v;
    int n;
    double d;
    double cmp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&x);
        scanf("%lf",&y);
        scanf("%lf",&v);
        scanf("%lf",&t);
        x=x*x;
        y=y*y;
        t=t*t;
        v=v*v;
        d=(x+y);
        cmp=(d/v);
        if(t>=cmp){
            printf("YES\n");
            continue;
        }
        else{
            printf("NO\n");
            continue;
        }
    }
    return 0;

}