class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, vector<int>> m;
        int n = mat.size(), ms = mat[0].size();
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                m[i-j].push_back(mat[i][j]);
            }
        }
        for(int k=-(ms-1);k<n;k++) {
            sort(m[k].begin(), m[k].end());
        }
        
        for(int i = n-1; i>=0;i--){
            for(int j = ms-1;j>=0;j--){
                mat[i][j] = m[i-j].back();
                m[i-j].pop_back();
            }
        }
        return mat;
    }
};