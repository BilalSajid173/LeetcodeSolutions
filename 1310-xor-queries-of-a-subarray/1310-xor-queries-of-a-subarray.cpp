class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prexor;
        int a = 0;
        for(auto x: arr){
            a = a^x;
            prexor.push_back(a);
        }
        vector<int> ans;
        for(auto q: queries){ 
           int x = q[0] > 0 ? prexor[q[0] - 1]^prexor[q[1]] : prexor[q[1]];
           ans.push_back(x);
        }
        return ans;
    }
};