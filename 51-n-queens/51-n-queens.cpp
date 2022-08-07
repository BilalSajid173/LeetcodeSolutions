class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        char a[10][10];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                a[i][j] = '.';
            }
        }
        
        nQueens(n,0,a);
        return ans;
    }
    
    void nQueens(int n, int i, char a[10][10]){
        if (i == n){
            vector<string> v;
            for(int x = 0;x<n;x++){
                string temp = "";
            for(int y = 0;y<n;y++){
                temp += a[x][y];
            }
                
                v.push_back(temp);
        }
            ans.push_back(v);
            return;
        }

    for (int j = 0; j < n; j++)
    {
        // check if the current position is safe to put a queen.
        if (issafe(n, i, j, a))
        {
            a[i][j] = 'Q';
            nQueens(n, i + 1, a);
            a[i][j] = '.'; 
        }
    }
    }
    
    bool issafe(int n, int i, int j, char a[10][10])
{
    for (int row = 0; row <= i; row++)
    {
        if (a[row][j] == 'Q')
            return false;
    }

    // checking along left diagonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (a[x][y] == 'Q')
            return false;
        x--;
        y--;
    }

    // checking along right diagonal
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (a[x][y] == 'Q')
            return false;
        x--;
        y++;
    }
    return true;
}
};