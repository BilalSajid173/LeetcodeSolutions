class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        vector<vector<int>> dp (n, (vector<int> (m,0)));
        if(nums1[0] == nums2[0]) {
            dp[0][0] = 1;
            ans = 1;
        }
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i] == nums2[0]){
                dp[i][0] = 1;
                ans = 1;
            }
        }
        for(int i = 0;i<nums2.size();i++){
            if(nums1[0] == nums2[i]){
                dp[0][i] = 1;
                ans = 1;
            }
        }
        for(int i = 1;i<nums1.size();i++){
            for(int j = 1;j<nums2.size();j++){
                if(nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                ans = max(dp[i][j],ans);
            }
        }
        return ans;
    }
};