class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(), nums1.end());
        
        vector<int> ans;
        for(int val: nums2){
            auto itr = s.find(val);
            if(itr != s.end()){
                ans.push_back(val);
                s.erase(itr);
            }
        }
        return ans;
    }
};