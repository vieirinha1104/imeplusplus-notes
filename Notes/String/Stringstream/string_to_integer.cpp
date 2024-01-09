#include <bits/stdc++.h>
#define N 1000000
using namespace std;


int main(){
    string s;
    cin >> s;
    int arr[4];
    for(int i=0;i<4;i++){
        stringstream ss;
        ss << s[i];
        ss >> arr[i];
    }
   for(int i=0;i<4;i++){
        cout << arr[i] << " ";
   }
   cout << "\n";
   
}