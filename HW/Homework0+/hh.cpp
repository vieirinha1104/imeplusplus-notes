#include <bits/stdc++.h>

using namespace std;

int lost_permutation(int n,int s,int *v){
  //Max elemento do vetor:
    int max=v[0];
    for(int i=1;i<n;i++){
            if(v[i]>max){
                max=v[i];
            }
    }
    //soma da permutacao:
    int sum=0;
    for(int i=1;i<max+1;i++){
        sum=sum+i;
    }
    //soma dos elementos do array:
    int aux_sum=0;
    for(int i=0;i<n;i++){
        aux_sum=aux_sum+v[i];
    }
    while(1){
        if((sum-aux_sum)==s){
                cout << "YES"<<"\n";
                return 0;
            }
            max=max+1;
            sum=sum+max;
        if( (sum-aux_sum)>s ){
                cout << "NO"<< "\n";
                return 0;
                }
            
    }
    }
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n,s;
        cin >> n >> s;
        int vector[n];
        for(int i=0;i<n;i++){
            cin >> vector[i];
        }
        lost_permutation(n,s,vector);
    }

    }