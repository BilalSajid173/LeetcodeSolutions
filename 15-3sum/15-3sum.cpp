class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i = 0;i<nums.size();i++){
            vector<int> v;
            v.push_back(nums[i]);
            int j = i+1, k = nums.size() - 1;
            while(j<k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++; 
                } else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                } else if(nums[i] + nums[j] + nums[k] == 0){
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    s.insert(v);
                    v.pop_back();
                    v.pop_back();
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto v : s){
            ans.push_back(v);
        }
        return ans;
    }
};