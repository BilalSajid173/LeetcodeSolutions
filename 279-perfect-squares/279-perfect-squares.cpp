class Solution {
public:
    int dp[10001] = {0};
    int numSquares(int n) {
        if(n==0) return 0;
        if(dp[n] != 0) return dp[n];
        int ans = INT_MAX;
        for(int i = 1;i<=(int)sqrt(n);i++){
            int x = n - i*i;
            ans = min(ans,1 + numSquares(x));
        }
        return dp[n] = ans;
    }
};