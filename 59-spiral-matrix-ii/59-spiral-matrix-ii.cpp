class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int u = 0, d = n - 1, l = 0, r = n - 1;
        vector<vector<int>> matrix(n, vector<int> (n));
        int a = 1;
        while (u <= d && l <= r) {
            for (int col = l; col <= r; col++) {
                matrix[u][col] = a;
                a++;
            }
            if (++u > d) {
                break;
            }
            for (int row = u; row <= d; row++) {
                matrix[row][r] = a; a++;
            }
            if (--r < l) {
                break;
            }
            for (int col = r; col >= l; col--) {
                matrix[d][col] = a; a++;
            }
            if (--d < u) {
                break;
            }
            for (int row = d; row >= u; row--) {
                matrix[row][l] = a; a++;
            }
            if (l++ > r) {
                break;
            }
        }
        return matrix;
    }
};