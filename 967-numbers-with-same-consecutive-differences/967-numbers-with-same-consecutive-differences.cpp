class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1;i<= 9;i++){
            helper(i,k,n, 1, ans);
        }
        return ans;
    }
    
    void helper(int num, int k, int n, int len, vector<int>& ans){
        if(len == n){
            ans.push_back(num);
            return;
        }
        int lastdig = num % 10;
        if(k == 0){
            int newnum = (num*10) + (lastdig + k);
            helper(newnum, k, n, len + 1, ans);
            return;
        }
        if((lastdig + k) <= 9){
            int newnum = (num*10) + (lastdig + k);
            helper(newnum, k, n, len + 1, ans);
        }
        if((lastdig - k) >= 0){
            int newnum = (num*10) + (lastdig - k);
            helper(newnum, k, n, len + 1, ans);
        }
        return;
    }
};