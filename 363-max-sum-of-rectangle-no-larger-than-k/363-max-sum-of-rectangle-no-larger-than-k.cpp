class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size(), m = matrix[0].size(), ans = INT_MIN;
        for(int i = 0;i<m;i++){
            vector<int> presum(n,0);
            for(int j = i;j<m;j++){
                for(int k = 0; k<n;k++){
                    presum[k] += matrix[k][j];
                }
                
                int cursum = 0;
                int curMax = INT_MIN;
                set<int> s;
                s.insert(0); //so that first value is not missed
                for(auto num: presum){
                    cursum += num;
                    auto it = s.lower_bound(cursum - k);
                    if(it != s.end()){
                        curMax = max(curMax, cursum - *it);
                    }
                    s.insert(cursum);
                }
                ans = max(ans,curMax);
            }
        }
        return ans;
    }
};