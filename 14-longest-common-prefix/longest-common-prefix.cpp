class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

if (strs.empty()){
    return "";
}
for( int i = 0;i<strs[0].length();i++){
    char ch = strs[0][i];

for(int f = 1; f<strs.size();f++){
    if(i==strs[f].length() || strs[f][i]!=ch){
        return strs[0].substr(0,i);
    }
}
}

return strs[0];

    }
};