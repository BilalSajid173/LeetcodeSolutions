class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<arr.size();i++){
            if(pq.size() == k){
                if(abs(arr[i] - x) < pq.top().first){
                    pq.pop();
                    pq.push({abs(arr[i] - x), arr[i]});
                }
            } else{
                pq.push({abs(arr[i] - x), arr[i]});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

//Binary Search Solution.

//https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)