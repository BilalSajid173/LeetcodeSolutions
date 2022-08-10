class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        bool dp[len][len];
        for(int i = 0;i<len;i++){
            for(int j = 0;j<len;j++){
                dp[i][j] = false;
            }
        }
        for(int i = 0;i<len;i++) dp[i][i] = true;
        int pal_strings = 0;
        for(int end = 0;end<len;end++){
            for(int start = end - 1; start >= 0;start--){
                if(s[start] == s[end]){
                    if((end - start == 1) || (dp[start+1][end - 1])){
                        dp[start][end] = true;
                        pal_strings++;
                    }
                }
            }
        }
        
        return pal_strings + len;
    }
};