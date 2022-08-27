class Solution {
public:
        int singleNumber(vector<int>& nums) {
            int count[32] = {0};
            for(int i = 0;i<nums.size();i++){
                int j = 31;
                long long int n = abs(nums[i]);
                while(n > 0){
                    int bit = n&1;
                    count[j] += bit;
                    j--;
                    n = n>>1;
                }
            }
            long long int ans = 0;
            int p = 0;
            for(int i = 31;i>=0;i--){
                count[i] = count[i] % 3;
                if(count[i])
                ans += 1<<p;
                p++;
            }
            int c = 0;
            for(auto x:nums){
                if(x == ans) c++;
            }
            return c == 1? ans : -ans;
        
    }
};