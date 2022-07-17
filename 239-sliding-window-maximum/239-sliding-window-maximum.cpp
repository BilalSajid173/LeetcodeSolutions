class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
vector<int> result;
    if (k == 0) return result;
    priority_queue<pair<int, int>> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        while (!w.empty() && w.top().second <= i-k)
            w.pop();
        w.push(make_pair(nums[i],i));
        if (i >= k-1)
            result.push_back(w.top().first);
    }
    return result;
//         deque<int> buffer;
//         vector<int> res;

//         for(auto i=0; i<nums.size();++i)
//         {
//             while(!buffer.empty() && nums[i]>=nums[buffer.back()]) buffer.pop_back();
//             buffer.push_back(i);

//             if(i>=k-1) res.push_back(nums[buffer.front()]);
//             if(buffer.front()<= i-k + 1) buffer.pop_front();
//         }
//         return res;
    }
};