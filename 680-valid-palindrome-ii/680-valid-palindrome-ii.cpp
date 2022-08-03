class Solution {
public:
    bool validPalindrome(string s) {
        
        int i = 0, j = s.length() - 1;
        while(i<=j){
            if(s[i] != s[j]){
                string s1 = s.substr( 0, i) + s.substr(i+ 1);
                string s2 = s.substr(0,j) + s.substr(j+1);
                bool x = helper(s1);
                bool y = helper(s2);
                return x || y;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool helper(string s){
        int i = 0, j = s.length() - 1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};