#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<int> vals(nums.begin(), nums.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int N = vals.size();

        vector<long long> cnt(N + 1, 0), sm(N + 1, 0);
        auto id = [&](int v) {
            return int(lower_bound(vals.begin(), vals.end(), v) - vals.begin()) + 1;
        };
        auto update = [&](int v, int dc) {
            for (int i = id(v); i <= N; i += i & -i) {
                cnt[i] += dc;
                sm[i] += (long long)dc * v;
            }
        };

        int LOG = 1;
        while ((1 << LOG) <= N) LOG++;

        // returns {m-th smallest value, sum of the m smallest values}
        auto smallest = [&](int m) {
            int pos = 0;
            long long rem = m, acc = 0;
            for (int b = LOG; b >= 0; b--) {
                int nxt = pos + (1 << b);
                if (nxt <= N && cnt[nxt] < rem) {
                    pos = nxt;
                    rem -= cnt[pos];
                    acc += sm[pos];
                }
            }
            long long v = vals[pos];
            return pair<long long, long long>(v, acc + rem * v);
        };

        const long long INF = LLONG_MAX / 4;
        int m = (x + 1) / 2;
        vector<long long> cost(n + 1, INF);  // cost[i]: window nums[i-x .. i-1]
        long long total = 0;

        for (int i = 0; i < n; i++) {
            update(nums[i], 1);
            total += nums[i];
            if (i >= x) {
                update(nums[i - x], -1);
                total -= nums[i - x];
            }
            if (i >= x - 1) {
                auto [med, low] = smallest(m);
                cost[i + 1] = med * m - low + (total - low) - med * (x - m);
            }
        }

        vector<long long> prev(n + 1, 0), cur(n + 1);
        for (int j = 0; j < k; j++) {
            fill(cur.begin(), cur.end(), INF);
            for (int i = x; i <= n; i++) {
                long long best = cur[i - 1];
                if (prev[i - x] < INF && cost[i] < INF)
                    best = min(best, prev[i - x] + cost[i]);
                cur[i] = best;
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};