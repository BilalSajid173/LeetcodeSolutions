class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<32;i++){
            int ones = 0, zero = 0;
            for(int j = 0;j<nums.size();j++){
                if(nums[j] % 2) ones++;
                else zero++;
                nums[j] >>= 1;
            }
            if(ones == n || zero == n) ans += 0;
            else ans += ones*zero;
        }
        return ans;
    }
};