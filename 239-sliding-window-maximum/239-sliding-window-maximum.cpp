class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start = 0;
        priority_queue<pair<int,int>> max_heap;
        int i = 0;
        while(i<k){
            max_heap.push({nums[i],i});
            i++;
        }
        vector<int> ans;
        ans.push_back(max_heap.top().first);
        while(k<nums.size()){
            start++;
            while(!max_heap.empty() && max_heap.top().second < start){
                max_heap.pop();
            }
            max_heap.push({nums[k],k});
            ans.push_back(max_heap.top().first);
            k++;
        }
        
        return ans;
        
    }
};