class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // seems to be the only condition to max out...
    }
        bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){
            int c = 0;
            while(a > (b<<(c+1))){
                c++;
            }
            ans += 1<<c;
            a -= b<<c;
        }
        return isPositive ? ans : -ans;
    }
};