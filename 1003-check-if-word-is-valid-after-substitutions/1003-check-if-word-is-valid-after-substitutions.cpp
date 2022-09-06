class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(auto c: s){
            if(c == 'a'){
                st.push(c);
            } else if(c == 'b' && !st.empty()){
                st.push(c);
            } else if(c == 'c' && !st.empty()){
                if(st.top() == 'b')
                    st.pop();
                else return false;
                if(st.top() == 'a')
                    st.pop();
                else return false;
            } else return false;
        }
        
        return st.empty();
    }
};