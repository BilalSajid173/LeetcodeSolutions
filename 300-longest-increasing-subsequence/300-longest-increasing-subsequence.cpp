class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        int dp[2500];
        
        for(int i = 0;i<nums.size();i++){
            dp[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int lis = 0;
        for(int i = 0;i<nums.size();i++){
            lis = max(lis,dp[i]);
        }
        return lis;
    }
};