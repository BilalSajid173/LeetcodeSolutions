class Solution {
public:
     int findRadius(vector<int>& A, vector<int>& H) {
        sort(A.begin(), A.end());
        sort(H.begin(), H.end());
        vector<int> res(A.size(), INT_MAX); 
        
        // For each house, calculate distance to nearest RHS heater
        for (int i = 0, h = 0; i < A.size() && h < H.size(); ) {
            if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
            else { h++; }
        }
        
        // For each house, calculate distance to nearest LHS heater
        for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
            if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }
            else { h--; }
        }
       
        return *max_element(res.begin(), res.end());
    }
//     int findRadius(vector<int>& houses, vector<int>& heaters) {
//         sort(houses.begin(),houses.end());
//         sort(heaters.begin(),heaters.end());
        
//         int n = houses.size();
//         int m = heaters.size();
        
//         int low = 0; //cann't define as 1, coz there will be a case where all the heaters will be at all the houses resp.
//         int high = max(*max_element(houses.begin(),houses.end()),*max_element(heaters.begin(),heaters.end())); //to reduce search space, will also work if defined as 1e9
        
//         int ans = 0;
//         while(low <= high){
//             int mid = low + (high-low)/2;
//             if(helper(houses,heaters,mid)==true){ //called the blackbox to find that is it possible for current radius to be the ans
//                 ans = mid;
//                 high = mid - 1; //to minimise the ans;
//             }
//             else{
//                 low = mid + 1; //go to the right coz this mid can't be one answer;
//             }
//         }
//         return ans;
//     }

    
//     bool helper(vector<int> houses, vector<int> heaters, int rad){
        
//         int i = 0,j = 0;
//         int n = houses.size(), m = heaters.size();
//         while(i < n){
//             if(j == m) return false;
            
//             int l = heaters[j] - rad;
//             int r = heaters[j] + rad;
//             if(houses[i] < l || houses[i] > r){
//                 j++;
//             } else {
//                 i++;
//             }
//         }
//         return true;
//     }
};