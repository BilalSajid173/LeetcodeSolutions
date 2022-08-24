class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x || y){
            ans += (x&1)^(y&1) ? 1 : 0;
            x = x>>1;
            y = y>>1;
        }
        return ans;
    }
};