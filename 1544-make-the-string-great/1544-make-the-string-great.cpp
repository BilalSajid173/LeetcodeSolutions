class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto c:s){
            if(!st.empty() && st.top() != c && (toupper(st.top()) == c || st.top() == toupper(c))){
                st.pop();
            } else {
                st.push(c);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};