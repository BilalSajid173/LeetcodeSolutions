class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> s;
        vector<bool> filled(nums.size(), false);
        for(int i = nums.size() - 1;i>=0;i--){
            while(!s.empty() && nums[i] >= s.top()) s.pop();
            if(!s.empty()){
                ans[i] = s.top();
                filled[i] = true;
            }
            s.push(nums[i]);
        }
        for(int i = nums.size() - 1;i>=0;i--){
            while(!s.empty() && nums[i] >= s.top()) s.pop();
            if(!s.empty() && filled[i] == false) {
                ans[i] = s.top();
                filled[i] = true;
            }
            s.push(nums[i]);
        }
        return ans;
    }
};