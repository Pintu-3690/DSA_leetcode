class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>c(nums1.begin(),nums1.end());
        c.insert(c.end(),nums2.begin(),nums2.end());
        sort(c.begin(),c.end());
        int n = c.size();
        if(n%2==0){
            return (c[n/2]+c[n/2-1])/2.0;
        }    
        else{
            return c[n/2];
        }
    }
};