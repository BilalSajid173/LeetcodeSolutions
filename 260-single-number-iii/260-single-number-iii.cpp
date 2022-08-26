class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int a = 0;
        for(auto x: nums) a = a^x;
        int pos = 0, temp = a;
        while((temp&1) != 1){
            pos++;
            temp = temp>>1;
        }
        int num = 1<<pos;
        int b = 0;
        for(auto x:nums){
            if((x&num) >= 1){
                b = b^x;
            }
        }
        int c = a^b;
        return {b,c};
    }
};