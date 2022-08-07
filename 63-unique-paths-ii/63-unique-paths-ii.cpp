class Solution {
public:
    int dp[100][100];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        for(int i = 0;i<100;i++){
            for(int j = 0;j<100;j++){
                dp[i][j] = -1;
            }
        }
        int m = obstacleGrid.size() - 1;
        int n = obstacleGrid[0].size() - 1;
        return helper(0,0,m,n,obstacleGrid);
    }
    
    int helper(int i, int j, int m,int n, vector<vector<int>> obg){
        if(i == m && j == n){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int op1 = 0, op2 = 0;
        if(i < m && obg[i+1][j] == 0){
            op1 = helper(i+1,j,m,n,obg);
        }
        if(j < n && obg[i][j+1] == 0){
            op2 = helper(i,j+1,m,n, obg);
        }
        
        return dp[i][j] = op1 + op2;
    }
};