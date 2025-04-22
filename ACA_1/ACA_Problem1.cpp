#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(long long mid, const vector<long long>& height, long long k) 
{
    long long tempcost = 0;
    for (long long h : height) {
        if (h > mid) {
            tempcost += ((h - mid) * (h + mid + 1)) / 2;
            if (tempcost > k) return false;
        }
    }
    return tempcost <= k;
}
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> height(n);
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }
        long long low = 0, high = 1e6, mid;
        while (high - low > 1) {
            mid = (low + high) / 2;
            if (check(mid, height, k)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        cout << high << endl;
    }
    return 0;
}
