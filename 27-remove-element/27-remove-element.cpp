class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while(i<nums.size()){
            if(nums[i] == val){
                i++;
            } else if(nums[i] != val){
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
        return j;
    }
};