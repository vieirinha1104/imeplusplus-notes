#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    double x1,y1,x2,y2;
    double a,b;
    cin >>t;
    for(int i=0;i<t;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        a=((y2)*(x1)*(x1)-(y1)*(x2)*(x2))/(x1*x2*(x1-x2));
        b=((x1)*(y2)-(y1)*(x2))/(x1*x2*(x1-x2));
        double ans=(a/b);
        cout << fixed << setprecision(12);
        cout << ans << "\n";
    }


}