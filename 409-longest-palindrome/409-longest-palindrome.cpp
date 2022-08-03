class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(int i = 0;i<s.length();i++){
            m[s[i]]++;
        }
        int maxlen = 0, oddlen = 0;
        for(auto x:m){
            if(x.second % 2 == 0){
                maxlen += x.second;
            } else {
                oddlen = max(oddlen, x.second);
                maxlen += x.second - 1;
            }
        }
        if(oddlen != 0){
            maxlen++;
        }
        return maxlen;
    }
};