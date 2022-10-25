class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string a = "";
        for(auto x:word1){
            a += x;
        }
        string b = "";
        for(auto x:word2){
            b += x;
        }
        
        return a == b;
    }
};