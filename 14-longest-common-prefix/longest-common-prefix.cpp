class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
          sort(s.begin(),s.end());
          string first = s.front();
          string last = s.back();
          int l = min(first.length(),last.length());
          int i = 0;
          while( i < l && first[i]==last[i]){
            i++;
        
          }
          return first.substr(0,i);    

    }
};