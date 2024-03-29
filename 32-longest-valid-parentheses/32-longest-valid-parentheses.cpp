class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            } else if(s[i] == ')'){
                st.pop();
                if(!st.empty()){
                    maxlen = max(maxlen,i - st.top());
                } else{
                    st.push(i);
                }
            }
        }
        return maxlen;
    }
};