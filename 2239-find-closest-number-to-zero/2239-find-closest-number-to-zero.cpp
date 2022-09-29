class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = INT_MIN;
        int mindiff = INT_MAX;
        for(auto x:nums){
            int diff = abs(x-0);
            if(diff < mindiff){
                mindiff = diff;
                closest = x;
            } else if(diff == mindiff){
                if(x > closest) closest = x;
            }
        }
        return closest;
    }
};