#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,q;
    int arr[100000];
    deque<int> fila;
    pair<int,int> p[200000];
    int a,b;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr[i]=x;
        fila.push_back(x);
    }
    if(q==0){
        return 0;
    }
    //Maximo elemento da fila:
    auto itr =max_element(arr,arr+n);
    long long index= itr-arr;
    //Ciclos:
    for(int i=0;i<index+n-1;i++){
        a=fila.front();
        p[i].first=a;
        fila.pop_front();
        b=fila.front();
        p[i].second=b;
        fila.pop_front();
        if(a>b){
            fila.push_front(a);
            fila.push_back(b);
        }
        else{
            fila.push_back(a);
            fila.push_front(b);
        }
    }
    long long m;
    for(int j=0;j<q;j++){
        cin >> m;
        if(m<=index){
            cout << p[m-1].first << " " << p[m-1].second <<"\n";
        }
       else{
        long long new_m=m-index-1;
        long long new_index=(index)+((new_m)%(n-1));
        cout << p[new_index].first << " " << p[new_index].second<<"\n";
        }
    }
}


    