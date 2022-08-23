class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n == 1) return true;
        // if(n % 4 != 0 || n == 0) return false;
        // return isPowerOfFour( n / 4);
        //Bit manipulation solution
        int no_of_ones = 0, pos = 1, one_pos = 0;
        while(n >= 1){
            if(n & 1){
                no_of_ones++;
                one_pos = pos;
            }
            n>>=1;
            pos++;
        }
        return no_of_ones == 1 && (one_pos & 1);
    }
};