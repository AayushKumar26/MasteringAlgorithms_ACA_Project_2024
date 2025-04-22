#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<climits>
using namespace std;

int minSubarray(vector<int>&nums,int k) 
{
        int n = nums.size();
        vector<long long>preSum(n + 1, 0);
        
        for (int i=0;i<n;i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        // for smallest x2-x1 with preSum[x2]-preSum[x1]>=k
        int ans = n+1; 
        deque<int>que; 

        for (int i= 0;i<=n;i++) 
        {
            while (que.empty()==false && preSum[i]<=preSum[que.back()]) 
            {
                que.pop_back();
            }
            while (que.empty()==false && preSum[i]>=preSum[que.front()]+k) 
            {
                ans = min(ans, i - que.front());
                que.pop_front();
            }

            que.push_back(i);
        }
        if (ans < (n + 1))
        return ans;
        else
        return -1;
}


int main() 
{
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++) 
    {
        cin>>nums[i];
    }
    int result = minSubarray(nums, k);
    cout << result << endl;

    return 0;
}
