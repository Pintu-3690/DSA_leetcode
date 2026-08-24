class Solution {
public:
    bool isValid(string s) {
        stack<char>mr;
        unordered_map<char ,char>match{
            {')','('},
            {'}','{'},
            {']','['}
        };
        for(char k : s){
            if(match.count(k)){
                if(mr.empty() || mr.top() != match[k]){
                    return false;
                }
                mr.pop();
               
        }
         else {
            mr.push(k);
            }
        }
        return mr.empty();
    }
};