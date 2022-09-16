class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp = vector<vector<int>> (multipliers.size(), (vector<int> (multipliers.size(), INT_MIN)));
        return helper(nums, multipliers, 0, nums.size() - 1, 0);
    }
    
    int helper(vector<int>& nums, vector<int>& mult, int i,int k, int j){
        if( j>=mult.size()) return 0;
        if(dp[i][k - (nums.size() - mult.size())] != INT_MIN) return dp[i][k - (nums.size() - mult.size())];
        int left = (nums[i] * mult[j]) + helper(nums, mult, i+1,k, j+1);
        int right = (nums[k] * mult[j]) + helper(nums, mult, i, k-1, j+1);
        return dp[i][k - (nums.size() - mult.size())] = max(left,right);
    }
};