class Solution {
public:
    vector<int> countBits(int n) {
        //O(nlogn) soln
        // vector<int> ans;
        // int i = 0;
        // while(i <= n){
        //     int x = i;
        //     int a = 0;
        //     while(x > 0){
        //         x = (x & (x - 1));
        //         a++;
        //     }
        //     ans.push_back(a);
        //     i++;
        // }
        // return ans;
        vector<int> ret(n+1, 0);
        for (int i = 1; i <= n; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};