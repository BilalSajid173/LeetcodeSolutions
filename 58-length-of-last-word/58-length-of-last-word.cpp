class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int lastlen = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == ' '){
                if(len != 0){
                lastlen = len;
                len = 0;  
                }
            } else if(s[i] != ' '){
                len++;
            }
        }
        if(len != 0){
            return len;
        }
        return lastlen;
    }
};