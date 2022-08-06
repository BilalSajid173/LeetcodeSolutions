class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(nums,0);
        vector<vector<int>> res;
        for(auto c :ans){
            res.push_back(c);
        }
        return res;
        
    }
    
    void helper(vector<int> &nums, int i){
        if(i==nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int j = i;j<nums.size();j++){
            swap(nums[i], nums[j]);
            helper(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
};