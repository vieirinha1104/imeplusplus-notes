#include <bits/stdc++.h>

using namespace std;
    long long n;
    vector<long long> pontos;
    long long m;
    long long a;
    pair<long long,long long> p;
    vector<long long> minimo;
    vector<pair<int,long long>> ans;
    vector<long long> soma;
    long long b=0;
    long long sum=0;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        b+=a;
        pontos.push_back(a);
        soma.push_back(b);
    }
   for(int i=0;i<pontos.size();i++){
        sum+=pontos[i];
   }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a;
        minimo.push_back(a);
        p.first=1;
        p.second=pontos[0];
        ans.push_back(p);
    }
    for(int i=0;i<ans.size();i++){
        if(minimo[i]>=sum){
                ans[i].first=n;
                ans[i].second=sum;
                cout << ans[i].second << " " << ans[i].first << "\n";
                continue;
        }
        if(minimo[i]<=pontos[0]){
            cout << ans[i].second << " " << ans[i].first << "\n";
            continue;
        }
        auto itr=lower_bound(soma.begin(),soma.end(),minimo[i]);
        int k= itr-soma.begin();
        ans[i].first=k+1;
        ans[i].second=soma[k];
        cout << ans[i].second << " " << ans[i].first << "\n";
    }






}