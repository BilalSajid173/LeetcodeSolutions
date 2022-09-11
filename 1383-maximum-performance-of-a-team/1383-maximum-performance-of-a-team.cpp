class Solution {
public:
    static bool compare(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)       {
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({speed[i], efficiency[i]});
        }
        sort(v.begin(), v.end(), compare);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long runningsum = 0;
        long long ans = 0;
        for(int i = 0;i<n;i++){
            if(pq.size() < k){
                pq.push(v[i].first);
                runningsum += v[i].first;
                ans = max(ans, runningsum*v[i].second);
            } else{
                if(v[i].first > pq.top()){
                   runningsum -= pq.top();
                   pq.pop();
                   pq.push(v[i].first);
                   runningsum += v[i].first;
                   ans = max(ans, runningsum * v[i].second); 
                }
            }
        }
        return (int)(ans%1000000007);
    }
    
    
    
    
//     int maxperf(int n, vector<int>& speed, vector<int>& eff, int k, int mineff, int i, int sumofspeed)  {
//         if(k == 0){
//             long long performance = (sumofspeed % 1000000007)*(mineff % 1000000007);
//             return performance % 1000000007;
//         }
        
//         if(i == n){
//             return 0;
//         }
        
//         int dontpick = maxperf(n, speed, eff, k, mineff, i+1, sumofspeed);
//         int pick = maxperf(n, speed, eff, k - 1, min(mineff, eff[i]), i + 1, sumofspeed + speed[i]);
//         return max(pick, dontpick);
//     }
};