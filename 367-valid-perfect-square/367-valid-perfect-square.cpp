class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int s = 1, e = num;
        while(s <= e){
            int mid = s + (e-s)/2;
            if((long long)mid*mid > num){
                e = mid - 1;
            } else if(mid*mid < num){
                s = mid + 1;
            } else if(mid*mid == num){
                return true;
            }
        }
        return false;
    }
};