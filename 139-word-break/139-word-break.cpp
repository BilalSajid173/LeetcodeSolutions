class Solution {
public:
    map<string, int> m;
    int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict){
            m[word] = 1;
        }
        for(int i = 0;i<301;i++){
            dp[i] = -1;
        }
        return helper(s,0);
    }
    
    bool helper(string s, int i){
        if(i == s.length()) return true;
        
        if(dp[i] != -1) return dp[i];
        bool ans = false;
        for(int j = i;j<s.length();j++){
            string x = s.substr(i,j-i+1);
            if(m.count(x)) {
                ans = ans || helper(s,j+1);
            }
        }
        return dp[i] = ans;
    }
};