#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    ll maximumTotalDamage(vector<int>& a) {
        map<int,int> cnt;
        for (int x : a) cnt[x]++;
        vector<pair<int,int>> v = {{-1000000000,0}};
        for (auto &p : cnt) v.push_back(p);
        int n = v.size();
        vector<ll> dp(n);
        ll best = 0;
        for (int i = 1, j = 1; i < n; i++) {
            while (j < i && v[j].first < v[i].first - 2)
                best = max(best, dp[j++]);
            dp[i] = best + 1LL * v[i].first * v[i].second;
        }
        return *max_element(dp.begin(), dp.end());
    }
};