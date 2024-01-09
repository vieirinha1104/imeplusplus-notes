#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int x=s.size();
    int aux=0,auxx=0;
    int cnt=0;
    if(x==1){
        int y=s[0];
        if(y>=97 && y<=122){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    else if(x%2==0){
        int z=x/2;
        int j=0;
        for(int i=0;i<z;i++){
            int a=s[j];
            if(a>=97 && a<=122){
                aux++;
            }
            j=j+2;
        }
        int k=1;
        for(int i=0;i<z;i++){
            int b=s[k];
            if(b>=65 && b<=90){
                auxx++;
            }
        k=k+2;
        }
        
        if(aux==z && auxx==z){
            cout<< "Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    else{
        int z=x/2;
        int j=0;
        for(int i=0;i<z+1;i++){
            int a=s[j];
            if(a>=97 && a<=122){
                aux++;
            }
             
            j=j+2;
        }
        int k=1;
        for(int i=0;i<z;i++){
            int b=s[k];
            if(b>=65 && b<=90){
                auxx++;
            }             
            k=k+2;
        }

        if(aux==z+1 && auxx==z){
            cout<< "Yes\n";
        }
        else{
            cout<<"No\n";
        }

    }
   
   
}