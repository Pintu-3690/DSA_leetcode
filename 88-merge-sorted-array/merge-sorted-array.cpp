class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int arr = m + n - 1;

        for (; arr >= 0; arr--) {
            if (q < 0) {
                break;
            }

            if (p >= 0 && nums1[p] > nums2[q]) {
                nums1[arr] = nums1[p];
                p--;
            }
            else {
                nums1[arr] = nums2[q];
                q--;
            }
        }
    }
};