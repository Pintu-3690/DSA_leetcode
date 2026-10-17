class Solution {
public:
    int shipWithinDays(vector<int>& weight, int d) {
        int left = *max_element(weight.begin(),weight.end());
        int right = accumulate( weight.begin(),weight.end(),0);
        while( left < right){
            int mid = left + ( right - left)/2;
            int days = 1;
            int crnt_Weight = 0;
            for( int i = 0; i < weight.size();i++){
                if( crnt_Weight + weight[i] > mid){
                    days++;
                    crnt_Weight = 0;
                }
                crnt_Weight += weight[i];
            }
            if( days > d){
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};