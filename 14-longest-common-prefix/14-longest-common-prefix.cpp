class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i = 1;i< strs.size() ;i++){
            prefix = commonprefix(prefix, strs[i]);
        }
        return prefix;
    }
    
    string commonprefix(string s1, string s2){
        string res = "";
        int len = min(s1.length(), s2.length());
        for(int i = 0; i< len; i++){
            if(s1[i] != s2[i]){
                break;
            }
            res += s1[i];
        }
        return res;
    }
};