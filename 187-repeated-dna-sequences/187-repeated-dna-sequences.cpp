class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10){
            return {};
        }
        map<string,int> m;
        set<string> ans;
        for(int i = 0;i<=s.length() - 10;i++){
            string x = s.substr(i,10);
            if(m.find(x) != m.end()) ans.insert(x);
            else m[x] = 1;
        }
        vector<string> v;
        for(auto a:ans){
            v.push_back(a);
        }
        return v;
    }
};