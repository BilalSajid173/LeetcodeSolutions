class Solution {
public:
    int dp[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][0] = triangle[0][0];
        for(int i = 1;i<n;i++){
            for(int j = 0;j<triangle[i].size();j++){
                int a = dp[i-1][j];
                int b = INT_MAX;
                if(j-1 >= 0){
                    b = dp[i-1][j-1];
                }
                dp[i][j] = triangle[i][j] + min(a,b);
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
    
//     int helper(vector<vector<int>> triangle, int i, int j){
//         if(i == triangle.size() - 1){
//             return triangle[i][j];
//         }
        
//         if(dp[i][j] != INT_MAX){
//             return dp[i][j];
//         }
        
//         int op1 = 0, op2 = 0;
//         op1 = helper(triangle, i+1, j);
//         op2 = helper(triangle, i+1, j+1);
//         return dp[i][j] = min(op1, op2) + triangle[i][j];
//     }
};