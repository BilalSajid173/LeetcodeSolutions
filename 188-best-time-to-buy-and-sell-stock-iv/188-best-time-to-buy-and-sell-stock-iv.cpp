class Solution {
public:
    vector<vector<vector<int>>> dp;
    int maxProfit(int k, vector<int>& prices) {
        dp= vector<vector<vector<int>>>(prices.size()+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return helper(k, prices, 0, 0);
    }
    
    int helper(int k, vector<int>& prices, bool buy, int i)  {
        if(k == 0 || i >= prices.size()) return 0;
        
        if(dp[i][k][buy] != -1){
            return dp[i][k][buy];
        }
        int profitfinal = 0;
        if(buy){
            int dontsell = helper(k, prices, true, i + 1);
            int profit = helper(k-1, prices, false, i + 1) + prices[i];
            // cout<<dp[k][i][buy]<<endl;
            profitfinal = max(profit, dontsell);
        }
        else{
        int dontpick = helper(k, prices, false, i + 1);
        int pick = helper(k, prices, true, i + 1) - prices[i];
        profitfinal = max(pick, dontpick);
        }
        return dp[i][k][buy] = profitfinal;
    }
};