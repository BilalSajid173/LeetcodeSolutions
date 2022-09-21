class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto x: nums){
            if(x%2 == 0) sum += x;
        }
        vector<int> ans;
        for(auto v:queries){
            int idx = v[1];
            int val = v[0];
            if(nums[idx] % 2 == 0){
                sum -= nums[idx];
            }
            nums[idx] += val;
            if(nums[idx] %2 == 0){
                sum += nums[idx];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};