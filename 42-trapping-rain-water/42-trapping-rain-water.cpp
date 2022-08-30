class Solution {
public:
    int trap(vector<int>& height) {
        // int total = 0, left_max = 0, right_max = 0;
        // for(int i = 0;i<height.size();i++){
        //     left_max = 0, right_max = 0;
        //     for(int j = 0;j<i;j++){
        //         left_max = max(left_max, height[j]);
        //     }
        //     for(int j = i+1;j<height.size();j++){
        //         right_max = max(right_max, height[j]);
        //     }
        //     if(min(left_max, right_max) > height[i])
        //     total += min(left_max, right_max) - height[i];
        // }
        // return total;
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