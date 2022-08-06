class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while(i<j){
            int mh = min(height[i], height[j]);
            ans = max(ans, (j-i)*mh);
            while(height[i] <= mh && i<j) i++;
            while(height[j] <= mh && i<j) j--;
        }
        return ans;
    }
};