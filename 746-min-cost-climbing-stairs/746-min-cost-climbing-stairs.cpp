class Solution {
public:
    int dp[1001];
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 0; i<1001;i++){
            dp[i] = -1;
        }
        return min(helper(cost,0), helper(cost,1));
    }
    
    int helper(vector<int> cost, int i){
        if(i== cost.size() - 1){
            return cost[i];
        }
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        
        int ans1 = helper(cost, i+1);
        int ans2 = helper(cost, i+2);
        int ans = cost[i] + min(ans1,ans2);
        return dp[i] = ans;
    }
};