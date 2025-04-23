
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;++i){
        cin>>coins[i];
    }
    vector<int>ways(x + 1, 0);
    ways[0]=1;
    for(int val:coins){
        for(int i=val;i<=x;++i){
            ways[i]=(ways[i]+ways[i-val])%MOD;
        }
    }
    cout<<ways[x]<<endl;
}
