class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        int fsum = 0;
        for(int i = 0;i<nums.size();i++){
            int x = nums[i];
            int j = i+1, k = nums.size() - 1;
            while(j<k){
                int sum = x + nums[j] + nums[k];
                if(sum > target){
                    k--;
                } else if(sum < target){
                    j++;
                }
                if(abs(sum - target) < mindiff){
                    mindiff = abs(sum-target);
                    fsum = sum;
                }
                if(sum - target == 0){
                    return fsum;
                }
            }
        }
        return fsum;
    }
};