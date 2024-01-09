#include <bits/stdc++.h>
#define k 1.000000011
using namespace std;

int n;
long long t;

double fast_exp(long long t){
    if(t==0){
        return 1; 
    }
    else if(t==1){
        return k;
    }
    else{
        if(t%2==0){
            double aux=fast_exp(t/2);
            return aux*aux;
        }
        else{
            double aux=fast_exp((t-1)/2);
            return aux*aux*k;
        }
    }
     
}
	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> t;
    double ans=n*fast_exp(t);
    cout << setprecision(30) << ans << "\n";
	return 0;
}