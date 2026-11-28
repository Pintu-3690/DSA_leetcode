#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        int maxF = 0;
        long long minPrice = items[0][1];

        for (const auto& it : items) {
            maxF = max(maxF, it[0]);
            minPrice = min(minPrice, static_cast<long long>(it[1]));
        }

        vector<int> freq(maxF + 1, 0);
        for (const auto& it : items) {
            ++freq[it[0]];
        }

        vector<int> multCount(maxF + 1, 0);
        for (int f = 1; f <= maxF; ++f) {
            for (int m = f; m <= maxF; m += f) {
                multCount[f] += freq[m];
            }
        }

        struct ItemUnit {
            long long price;
            long long gain;
        };
        vector<ItemUnit> units;
        units.reserve(n);
        for (const auto& it : items) {
            long long g = static_cast<long long>(multCount[it[0]]) - 1;
            units.push_back({static_cast<long long>(it[1]), max(0LL, g)});
        }

        sort(units.begin(), units.end(), [](const ItemUnit& a, const ItemUnit& b) {
            return a.price < b.price;
        });

        long long remBudget = budget;
        long long totalItems = 0;

        for (const auto& u : units) {
            if (u.gain > 0 && u.price < 2LL * minPrice && remBudget >= u.price) {
                long long take = min(u.gain, remBudget / u.price);
                totalItems += 2LL * take;
                remBudget -= take * u.price;
            }
        }

        if (remBudget >= minPrice) {
            totalItems += remBudget / minPrice;
        }

        return static_cast<int>(totalItems);
    }
};