class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        return helper(1,n, "1");
    }
    
    string helper(int i, int n, string s){
        if(i == n){
            return s;
        }
        string x = "";
        int cnt = 0;
        for(int j = 0;j<s.length() - 1;j++){
            if(s[j+1] == s[j]){
                cnt++;
            } else {
                cnt += 1;
                x += to_string(cnt) + s[j];
                cnt = 0;
            }
        }
        x += to_string(cnt + 1) + s[s.length() - 1];
        return helper(i + 1, n, x);
    }
};