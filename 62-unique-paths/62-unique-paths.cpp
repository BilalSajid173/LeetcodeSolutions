class Solution {
public:
    int dp[100][100];
    int uniquePaths(int m, int n) {
        for(int i = 0;i<100;i++){
            for(int j = 0;j<100;j++){
                dp[i][j] = -1;
            }
        }
        return helper(0,0,m-1,n-1);
    }
    
    int helper(int i, int j, int m,int n){
        if(i == m && j == n){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int op1 = 0, op2 = 0;
        if(i < m){
            op1 = helper(i+1,j,m,n);
        }
        if(j < n){
            op2 = helper(i,j+1,m,n);
        }
        
        return dp[i][j] = op1 + op2;
    }
};