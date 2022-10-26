class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> prefix;
        int sum = 0;
        for(auto x:nums){
            sum += x;
            prefix.push_back(sum);
        }
        
        map<int,int> m{{0,0}};
        for(int i = 0;i<prefix.size();i++){
            int rem = prefix[i]%k;
            if(m.find(rem) != m.end()){
                if(m[rem] < i) return true;
            }
            else m[rem] = i + 1;
        }
        return false;
    }
};