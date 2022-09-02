class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> nums;
        string res = "";
        int num = 0;
        for(auto c: s){
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            } else if(isalpha(c)){
                res += c;            
            } 
            else if(c == '['){
            st.push(res);
            nums.push(num);
            res = "";
            num = 0;
        } else if(c == ']'){
            string tmp = "";
            for(int i = 0;i<nums.top();i++){
                tmp += res;
            }
            res = st.top() + tmp;
            st.pop();
            nums.pop();
        }
        }
        return res;
    }
};