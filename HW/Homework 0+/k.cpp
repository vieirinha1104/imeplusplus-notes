#include <bits/stdc++.h>

using namespace std;



int main(){
   double n,a,b,r;
   cin >> n >> a >> b >> r;
   int aux=0;
   for(int i=0;i<n;i++){
    double x,y;
    cin >> x >> y;
    if(((x-a)*(x-a)+(y-b)*(y-b)-r*r)<=0){
       aux++;
    }
   }
    cout << aux << "\n";
}