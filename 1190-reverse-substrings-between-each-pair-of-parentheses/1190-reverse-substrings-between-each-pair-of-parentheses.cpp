class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string ans = "";
        for(auto c:s){
            if(isalpha(c)){
                ans += c;
            } else if(c == '('){
                st.push(ans);
                ans = "";
            } else if(c == ')'){
                reverse(ans.begin(),ans.end());
                ans = st.top() + ans;
                st.pop();
            }
        }
        return ans;
    }
};