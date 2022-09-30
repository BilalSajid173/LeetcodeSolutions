class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> ans (n, vector<int> (n, -1));
        return totalWays(ans, 0, n);
    }
    
    int totalWays(vector<vector<int>> v, int k, int n){
        if(k == n) return 1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(isPossible(v, k, i, n)){
                v[k][i] = 1;
                ans += totalWays(v, k + 1, n);
                v[k][i] = -1;
            }
        }
        return ans;
    }
    bool isPossible(vector<vector<int>> &board, int k, int i, int n){
        //column
        for(int j = 0; j <= k; j++){
            if(board[j][i] == 1) return false;
        }
        //left diagonal
        int x = k, y = i;
        while(x > 0 && y > 0){
            if(board[x-1][y-1] == 1) return false;
            x--; y--;
        }
        //right diagonal
        x = k;
        y = i;
        while(x > 0 && y < n - 1){
            if(board[x - 1][y + 1] == 1) return false;
            x--; y++;
        }
        return true;
    }
};