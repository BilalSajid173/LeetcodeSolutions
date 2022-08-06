class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        for(int i = 0;i<101;i++){
            dp[i] = -1;
        }
        return helper(nums,0);
    }
    
    int helper(vector<int> nums, int i){
        if(i >= nums.size()){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int op1 = nums[i] + helper(nums, i + 2);
        int op2 = 0;
        if(i + 1 <= nums.size() - 1)
        op2 = nums[i+1] + helper(nums, i+3);
        return dp[i] = max(op1,op2);
    }
};