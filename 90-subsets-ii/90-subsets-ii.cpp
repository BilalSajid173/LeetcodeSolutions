class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(nums,temp,0);
        vector<vector<int>> res;
        for(auto v:ans) res.push_back(v);
        return res;
        
    }
    
    void helper(vector<int> nums, vector<int> &temp, int i){
        if(i == nums.size()){
            ans.insert(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        helper(nums, temp, i+1);
        temp.pop_back();
        helper(nums, temp, i+1);
    }
};