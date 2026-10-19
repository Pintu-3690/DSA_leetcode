class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>S;
        unordered_map<int,int>R;
        for( int i = 0; i<nums1.size();i++){
            for( int j=0;j<nums2.size();j++){
                if( nums1[i]==nums2[j] && R.count(nums1[i])==0){
                    R.insert({nums1[i],1});
                    S.push_back(nums1[i]);
                }
            }
        }
        return S;
    }
};