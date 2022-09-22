class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size() - 1;
        int sum = INT_MIN;
        while(left < right){
            sum = max(sum, (nums[left] + nums[right]));
            left++;right--;
        }
        return sum;
    }
};