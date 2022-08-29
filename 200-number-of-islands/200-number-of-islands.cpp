class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        int offsets[] = {0, 1, 0, -1, 0};
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    count++;
                    grid[i][j] = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                q.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};