class Solution {
public:
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        set<string> dic;
        for(auto w : dict){
            dic.insert(w);
        }
        return helper(s, dic);
    }
    
    vector<string> helper(string s, set<string> dict){
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,helper(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
//     vector<string> ans;
//     map<string,int> m;
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         for(auto w: wordDict) {
//             m[w] = 1;
//         }
//         helper(s,"", 0);
//         return ans;
//     }
    
//     void helper(string s, string a, int i){
//         if(i == s.length()){
//             ans.push_back(a.substr(0, a.length() - 1));
//             return;
//         }
        
//         for(int j = i;j<s.length();j++){
//             string x = s.substr(i, j-i+1);
//             if(m.count(x)){
//                 helper(s, a + x + " ", j+1);
//             }
//         }
//         return;
//     }
};