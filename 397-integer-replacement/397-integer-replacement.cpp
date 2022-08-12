class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if (n == 3)
        {
            return 2;
        }
        if (n == INT_MAX)
            return 32;
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        if(n%2 == 0) {
            op1 = integerReplacement(n/2);
        } else {
        op2 = integerReplacement(n-1);
            if((n+1) % 4 == 0)
        op3 = integerReplacement(n + 1);
        }
        return 1 + min(op1, min(op2,op3));
    }
};