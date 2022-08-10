class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        bool dp[len][len];
        for(int i = 0;i<len;i++){
            for(int j = 0;j<len;j++){
                dp[i][j] = false;
            }
        }
        for(int i = 0;i<len;i++) dp[i][i] = true;
        
        int max_pal_len = 1, cur_pal_len = 1;
        int pal_st = 0;
        for(int end = 0;end<len;end++){
            for(int start = end - 1; start >= 0;start--){
                if(s[start] == s[end]){
                    if((end - start == 1) || (dp[start+1][end - 1])){
                        dp[start][end] = true;
                        cur_pal_len = end - start + 1; 
                    }
                    if(cur_pal_len > max_pal_len){
                        pal_st = start;
                        max_pal_len = cur_pal_len;
                    }
                }
            }
        }
        
        return s.substr(pal_st, max_pal_len);
    }
    
//Brute Force
//     string helper(string s, int i){
//         if(i == s.length()) return "";
//         string ans = "";
//         for(int j = i; j< s.length();j++){
//             if(issubstring(s,i,j)){
//                 string x = s.substr(i, j-i+1);
//                 if(x.length() > ans.length()){
//                     ans = x;
//                 }
//             }
//         }
//         string next = helper(s,i+1);
//         if(next.length() > ans.length()) return next;
//         return ans;
//     }
    
//     bool issubstring(string s, int st, int e){
//         while(st<=e){
//             if(s[st] != s[e]) return false;
//             st++; e--;
//         }
//         return true;
//     }
};