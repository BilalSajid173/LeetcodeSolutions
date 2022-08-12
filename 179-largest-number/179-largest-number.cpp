class Solution {
public:
     static bool compare(string a, string b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto i : nums){
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end(), compare);
        string ans;
            for(auto x:v) ans += x;
        while(ans[0] == '0' && ans.length() > 1) ans.erase(0,1);
        
        return ans;
    }
};