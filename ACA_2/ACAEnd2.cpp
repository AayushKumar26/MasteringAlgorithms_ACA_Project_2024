#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
static bool comparator(vector<int> &v1,vector<int> &v2){
    return v1[1] < v2[1];
}
public:
    int scheduleCourse(vector<vector<int>>&c){
        priority_queue<int>pq;
        int res=0;
        sort(c.begin(),c.end(),comparator);
        int duration=0;
        for(int i=0;i<c.size();i++){
            duration+=c[i][0];
            pq.push(c[i][0]);
            if(duration>c[i][1]){
                duration-=pq.top();
                pq.pop();
            }
            res=max(res,int(pq.size()));
        }
        return res;
    }
};
