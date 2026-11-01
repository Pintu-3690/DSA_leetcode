#include <vector>
#include <algorithm>

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = ranges::min(nums);
        long long moves = 0;
        
        for (int num : nums) {
            moves += (num - min_val);
        }
        
        return static_cast<int>(moves);
    }
};