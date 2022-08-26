class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        helper(s,0);
        return ans;
    }
    
    void helper(string s, int i){
        if(i == s.length()) {
            ans.push_back(s);
            return;
        }
        char c = s[i];
        s[i] = isupper(c) ? tolower(c) : toupper(c);
        helper(s, i+1);
        if(isalpha(c)){
            s[i] = c;
            helper(s,i+1);
        }
    }
};