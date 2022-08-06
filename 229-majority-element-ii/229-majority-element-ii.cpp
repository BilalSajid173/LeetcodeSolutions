class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> ans;
        int x = nums.size() / 3;
        for(auto a : m){
            if(a.second > x){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};