class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(auto c :s){
            if(st.empty() || c != st.top().first){
                st.push({c,1});
            } else if(st.top().first == c){
                int x = st.top().second;
                st.pop();
                st.push({c,x + 1});
            }
            if(st.top().second == k){
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            int x = st.top().second;
            char c = st.top().first;
            string t = "";
            while(x){
                t += c;
                x--;
            }
            ans = t + ans;
            st.pop();
        }
        return ans;
    }
};