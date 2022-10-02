class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // dp = vector<vector<int>> (n + 1, vector<int>(target + 1, -1));
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helper(n,k,target, dp);
    }
    
    int helper(int n, int k, int target, vector<vector<int>> &dp){
        if(n==0 && target == 0) return dp[n][target] = 1;
        if(n == 0 || target == 0) return dp[n][target] = 0;
        if(dp[n][target] != -1) return dp[n][target];
        long long int numOfWays = 0;
        for(int i = 1;i <= k;i++){
            if((target - i) >= 0){
                numOfWays = (numOfWays + helper(n-1, k, target - i, dp)) % 1000000007;
            }
        }
        return dp[n][target] = numOfWays;
    }
};