class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1;i++){
            bool swapval = false;
            for(int j = 0; j< n-1;j++){
                if( nums[j] > nums[j+1]){
                    swap( nums[j],nums[j+1]);
                    swapval = true;
                }
            }
            if( !swapval){
            break;
        }
        } 

        
    }
};