class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int start = 0;
//         priority_queue<pair<int,int>> max_heap;
//         int i = 0;
//         while(i<k){
//             max_heap.push({nums[i],i});
//             i++;
//         }
//         vector<int> ans;
//         ans.push_back(max_heap.top().first);
//         while(k<nums.size()){
//             start++;
//             while(!max_heap.empty() && max_heap.top().second < start){
//                 max_heap.pop();
//             }
//             max_heap.push({nums[k],k});
//             ans.push_back(max_heap.top().first);
//             k++;
//         }
        
//         return ans;
        deque<int> buffer;
        vector<int> res;

        for(auto i=0; i<nums.size();++i)
        {
            while(!buffer.empty() && nums[i]>=nums[buffer.back()]) buffer.pop_back();
            buffer.push_back(i);

            if(i>=k-1) res.push_back(nums[buffer.front()]);
            if(buffer.front()<= i-k + 1) buffer.pop_front();
        }
        return res;
    }
};