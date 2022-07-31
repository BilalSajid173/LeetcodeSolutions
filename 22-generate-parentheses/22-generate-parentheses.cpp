class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s = "";
        helperfunction(s,n,0,0);
        return ans;
    }
    
    void helperfunction(string s, int n, int l, int r){
        if(l==n && r==n){
            ans.push_back(s);
        }
        if(l<n){
            helperfunction(s+"(",n,l+1,r);
        }
        if(r<l){
            helperfunction(s+")",n,l,r+1);
        }
        return;
    }
};