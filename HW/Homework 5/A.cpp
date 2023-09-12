#include <bits/stdc++.h>

using namespace std;

void homework_fila(int n,int *arr){
    deque<int> fila;
    if(n==1){
        cout <<1<<"\n";
    }
    else if(n==2){
  
    cout << 1 << " " << 2<<"\n";
}
else{
    fila.push_front(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]<fila.front()){
            fila.push_front(arr[i]);
        }
        else{
            fila.push_back(arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<fila.front()<<" ";
        fila.pop_front();
    }
    cout<< "\n";
}
}



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
   int t;
   cin >> t;
   for(int i=0;i<t;i++){
    int n;
    int arr[200000];
    cin >> n;
    for(int j=0;j<200000;j++){
        cin >> arr[j];
        if(j==(n-1)){
            break;
        }
    }
    homework_fila(n,arr);
   }

    
}