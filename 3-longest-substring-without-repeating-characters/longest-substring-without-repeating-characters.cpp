class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>chIndx(128,-1);
        int l = 0;
        int maxx = 0;
        for( int i =0; i< s.length();i++){
            char c = s[i];
            if( chIndx[c]>=l){
                l = chIndx[c]+1;
            }
            chIndx[c]=i;
            maxx = max( maxx,i-l+1);
        }
        return maxx;

    }
};