class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int, int> m;
        stack<int> s;
        for(int i = nums2.size() - 1;i>=0;i--){
            while(!s.empty() && nums2[i] > s.top()) s.pop();
            if(s.empty()) m[nums2[i]] = -1;
            else m[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto x:nums1){
            ans.push_back(m[x]);
        }
        return ans;
    }
};