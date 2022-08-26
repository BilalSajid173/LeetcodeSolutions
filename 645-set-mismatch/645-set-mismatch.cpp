class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        for(auto x:nums) m[x]++;
        int dup = -1, missing = 1;
        for(int i = 1;i<=nums.size();i++){
            if(m.find(i) != m.end()){
                if(m[i]== 2){
                dup = i;
            }
            }
            else missing = i;
        }
        return {dup,missing};
    }
};