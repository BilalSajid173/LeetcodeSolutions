class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int p = 0;
        for(int i = columnTitle.length() - 1; i>=0;i--){
            ans += pow(26, p++)*(columnTitle[i] - 64);
        }
        return ans;
    }
};