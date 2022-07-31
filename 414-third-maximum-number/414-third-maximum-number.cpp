class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int i = 0;i< nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size() >= 3){
            auto itr = s.end();
            itr--;
            itr--;
            itr--;
            return *itr; 
        }
        auto itr = s.end();
        itr--;
        return *itr;
    }
};