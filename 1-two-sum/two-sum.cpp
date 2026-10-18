class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size();
        unordered_map<int,int>s;
        for( int i = 0; i< n;i++){
            int complement = target - nums[i];
            if(s.find(complement) != s.end()){
                return {s[complement],i};
            }
            s[nums[i]]=i;
        }
        return {};
    }
};