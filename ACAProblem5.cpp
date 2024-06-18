#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sumDigits(const string &s) 
{
    int sum = 0;
    for (char c : s) 
    {
        sum += c - '0';
    }
    return sum;
}

int main() 
{
    int n;
    cin >> n;
    vector<string>strings(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>strings[i];
    }
    unordered_map<int,unordered_map<int,vector<string>>>hashMap;

    for (const string &s : strings) {
        int len = s.length();
        int sum = sumDigits(s);
        hashMap[len][sum].push_back(s);
    }
    int pairCount = 0;
    for (const string &s : strings) {
        int len1 = s.length();
        int sum1 = sumDigits(s);
        int requiredLen2 = 12 - len1;
        int requiredSum2 = 50 - sum1;

        if (requiredLen2 > 0 && requiredLen2 <= 10) {
            auto it = hashMap.find(requiredLen2);
            if (it != hashMap.end()) {
                auto sumMap = it->second.find(requiredSum2);
                if (sumMap != it->second.end()) {
                    pairCount += sumMap->second.size();
                }
            }
        }
    }

    cout << pairCount / 2 << endl;

    return 0;
}
