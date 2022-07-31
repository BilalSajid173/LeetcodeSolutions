class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        multiset<char> st;
        for(auto c:s){
            st.insert(c);
        }
        for(auto c:t){
            auto it = st.find(c);
            if(it == st.end()){
                return false;
            }
            st.erase(it);
        }
        return true;
    }
};