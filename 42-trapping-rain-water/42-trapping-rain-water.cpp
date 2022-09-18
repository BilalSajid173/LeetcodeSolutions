class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int leftdp[n];
        int rightdp[n];
        leftdp[0] = 0;
        rightdp[n-1] = 0;
        for(int i = 1;i<n;i++){
            leftdp[i] = max(height[i-1], leftdp[i-1]); 
        }
        // for(auto x: leftdp){
        //     cout<<x<< " ";
        // }
        for(int i = n-2;i>=0;i--){
            rightdp[i] = max(height[i+1], rightdp[i+1]);
        }
        // for(auto x: rightdp){
        //     cout<<x<< " ";
        // }
        for(int i = 0;i<height.size();i++){
            int left = leftdp[i];
            int right = rightdp[i];
            if(min(left, right) > height[i]){
                total += min(left,right) - height[i];
            }
        }
        return total;
    }
};