class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length()){
            return false;
        }
        unordered_map<char,int>count;
        for( char ch : s){
            count[ch]+=1;
        }
        for( char ch : t){
            count[ch]-=1;
        }
        for( auto &pair : count){
            if( pair.second != 0){
                return false;
            }
        }
        return true;
    }
};