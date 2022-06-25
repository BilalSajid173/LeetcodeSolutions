class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            if(m[nums[i]]){
                m[nums[i]]++;
            }
            else{
                m[nums[i]] = 1;
            }
        }
        priority_queue<p,vector<p>, greater<p>> pq;
        for(auto c:m){
            if(pq.size() == k){
                if(c.second > pq.top().first){
                    pq.pop();
                    pq.push({c.second,c.first});
                }
            } else {
                pq.push({c.second,c.first});
            }
        }
        
        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }
};