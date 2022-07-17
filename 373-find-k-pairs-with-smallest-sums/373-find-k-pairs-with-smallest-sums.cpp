class Solution {
public:
    int min(int a, int b){
        if(a<=b)return a;
        else return b;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>>pqmax;
        for(int i = 0; i<min(nums1.size(),k);i++){
            for(int j = 0;j<min(nums2.size(),k);j++){
                if(pqmax.size() < k){
                    pqmax.push({nums1[i] + nums2[j],{nums1[i],nums2[j]}});
                } else if((nums1[i] + nums2[j]) < pqmax.top().first){
                    pqmax.pop();
                    pqmax.push({nums1[i] + nums2[j],{nums1[i],nums2[j]}});
                } else{
                    break;
                }
            }
        }
        
        while(!pqmax.empty()){
            vector<int> v;
            v.push_back(pqmax.top().second.first);
            v.push_back(pqmax.top().second.second);
            ans.push_back(v);
            pqmax.pop();
        }
        
        return ans;
        
    }
};