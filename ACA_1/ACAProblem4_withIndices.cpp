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
        vector<long long>totcost(k + 1, 0);
        for(int i=0;i<n;++i) {
            for(int j=k;j>=cost[i];--j) {
                if (totcost[j]<totcost[j-cost[i]]+num[i]) 
                {
                    totcost[j]=totcost[j-cost[i]]+num[i];
                }
            }
        }
        cout<<totcost[k]<<endl;
        
        cout<<endl;
    }

    return 0;
}
