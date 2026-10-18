class Solution {
public:
   bool check( vector<int>&position,int m, int dist){
    int cnt = 1;
    int prev = position[0];
    for( int i = 1; i<position.size();i++){
        if( position[i] - prev >= dist){
            prev = position[i];
            cnt++;
        }
    }
    return ( cnt >= m);
   }
    int maxDistance(vector<int>& position, int m) {
         sort( position.begin(),position.end());
        int res = 0;
        int low = 1;
        int high = position.back()-position[0];
       
        while( low <= high){
            int mid = low + ( high - low)/2;
            if( check(position,m,mid)){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return res;
    }
};