class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev_idx(n,-1);
        int max_idx = 0;
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev_idx[i] = j;
                }
            }
            if(dp[i] > dp[max_idx]){
                max_idx = i;
            }
        }
        
        vector<int> ans;
        int t = max_idx;
        while(t >= 0){
            ans.push_back(nums[t]);
            t = prev_idx[t];
        }
        return ans;
    }
};