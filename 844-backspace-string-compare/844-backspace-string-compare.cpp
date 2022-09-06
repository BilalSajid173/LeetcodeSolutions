class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string s1, t1;
        
        for(int i = 0;i< s.length();i++){
            if(s[i] != '#'){
                s1 += s[i];
            } else{
                if(!s1.empty())
                s1.pop_back();
            }
        }
        
        for(int i = 0;i< t.length();i++){
            if(t[i] != '#'){
                t1 += t[i];
            } else{
                if(!t1.empty())
                t1.pop_back();
            }
        }
        
        if(s1 == t1)
            return true;
        
        return false;
        
    }
};