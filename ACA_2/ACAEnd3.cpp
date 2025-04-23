#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
vector<vector<ll>>multi(const vector<vector<ll>>& A, const vector<vector<ll>>& B, ll N){
    vector<vector<ll>> C(N, vector<ll>(N, 0));
    for(ll i=0;i<N;++i){
        for(ll j=0;j<N;++j){
            for(ll k=0;k<N;++k){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
            }
        }
    }
    return C;
}
vector<vector<ll>>matrixExp(vector<vector<ll>> base, ll exp, ll N){
    vector<vector<ll>> result(N, vector<ll>(N, 0));
    for (ll i=0;i<N;++i){
        result[i][i]=1;
    }
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multi(result, base, N);
        }
        base = multi(base, base, N);
        exp /= 2;
    }
    return result;
}

int main(){
    ll N,K;
    cin>>N>>K;
    vector<vector<ll>>adjointMatrix(N, vector<ll>(N));
    for(ll i=0;i<N;++i){
        for(ll j=0;j<N;++j){
            cin>>adjointMatrix[i][j];
        }
    }
    vector<vector<ll>> result=matrixExp(adjointMatrix, K, N);
    ll count = 0;
    for(ll i = 0; i < N; ++i){
        for (ll j = 0; j < N; ++j){
            count = (count + result[i][j]) % MOD;
        }
    }

    cout<<count<<endl;
    return 0;
}
