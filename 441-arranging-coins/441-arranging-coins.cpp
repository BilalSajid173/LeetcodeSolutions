class Solution {
public:
    int arrangeCoins(int n) {
        long long s = 0, e = n;
        while(s <= e){
            long long mid = s + (e - s) / 2;
            long long coins = ((mid + 1)*(mid)) / 2;
            if(coins == n) return (int)mid;
            if(coins < n){
                s = mid + 1;
            } else if(coins > n) {
                e = mid - 1;
            }
        } 
        return (int)e;
    }
};