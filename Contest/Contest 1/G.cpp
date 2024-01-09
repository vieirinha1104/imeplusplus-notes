#include <bits/stdc++.h>

using namespace std;

int main(){
    long long arr[200000];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int aux=-1;
    int tam;
    set<long long> s1;
    set<int> s2;
   for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if(aux==s1.size()){
            s1.empty();
            aux=-1;
            break;
        }
        aux=s1.size();
        s1.insert(arr[j]);
        tam=s1.size();
    }
    s2.insert(tam);
   }
   
   auto itr=s2.end();
   itr--;
   cout << *itr << "\n";

    }
