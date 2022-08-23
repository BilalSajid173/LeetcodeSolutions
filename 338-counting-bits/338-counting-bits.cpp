class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        int i = 0;
        while(i <= n){
            int x = i;
            int a = 0;
            while(x > 0){
                x = (x & (x - 1));
                a++;
            }
            ans.push_back(a);
            i++;
        }
        return ans;
    }
};