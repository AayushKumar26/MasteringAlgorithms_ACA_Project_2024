#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<int>cost(n),num(n);
        for(int i=0;i<n;++i) 
        {
            cin>>cost[i]>>num[i];
        }
        vector<long long>maxOreos(k + 1, 0);
        vector<vector<int>>indices(k + 1);
        for(int i=0;i<n;++i) {
            for(int j=k;j>=cost[i];--j) {
                if (maxOreos[j]<maxOreos[j-cost[i]]+num[i]) {
                    maxOreos[j]=maxOreos[j-cost[i]]+num[i];
                    indices[j]=indices[j-cost[i]];
                    indices[j].push_back(i + 1); 
                }
            }
        }
        cout<<maxOreos[k]<<endl;
        for(int index : indices[k]) 
        {
            cout<<index<<" ";
        }
        cout<<endl;
    }

    return 0;
}
