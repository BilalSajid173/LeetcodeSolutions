class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int ans = 0;
        for(int i = 0;i<s.length();i++){
            char a = s[i];
            char b = t[i];
            ans = ans^(int)a^(int)b;
        }
        return (char)ans^(int)t[t.length() - 1];
    }
};