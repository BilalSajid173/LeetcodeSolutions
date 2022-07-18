class Solution {
    typedef pair<int,pair<int,int>> node;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        // priority_queue<node> pqmax;
        priority_queue<node, vector<node>, greater<node>> pqmin;
        int mx = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            mx = max(mx, nums[i][0]);
            pqmin.push({nums[i][0],{i,0}});
        }
        
        pair<int,int> ans;
        ans = {pqmin.top().first, mx};
        
        while(!pqmin.empty()){
            int i = pqmin.top().second.first;
            int j = pqmin.top().second.second;
            if((j+1) < nums[i].size()){
                pqmin.pop();
                pqmin.push({nums[i][j+1], {i,j+1}});
                mx = max(mx,nums[i][j+1]);
                int diff = mx - pqmin.top().first;
                if(diff < (ans.second - ans.first)){
                    ans.first = pqmin.top().first;
                    ans.second = mx;
                }
            } else{
                break;
            }
        }
        vector<int> v;
        v.push_back(ans.first);
        v.push_back(ans.second);
        return v;
        
    }
};