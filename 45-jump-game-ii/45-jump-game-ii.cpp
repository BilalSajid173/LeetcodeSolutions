class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1){
            return 0;
        }
        int jumps = 1;
        int dist = nums[0];
        int maxdist = 0;
        int idx = 0;
        for(int i = 1;i<nums.size();i++){
            if(dist >= i && i + nums[i] > maxdist){
                maxdist = i + nums[i];
                idx = i;
            }
            else if(dist < i){
                dist = maxdist;
                maxdist = 0;
                i = idx;
                jumps++;
            } 
        }
        return jumps;
    }
};