class Solution {
public:
    bool isPowerOfTwo(int n) {
        
//         if(n <= 0)
//             return false;
//         if(n==1 )
//             return true;
        
//         if(n%2 != 0)
//             return false;
        
//         return isPowerOfTwo(n/2);
        //Bitmasking solution
        if(n == 1) return true;
        int num_of_ones = 0;
        while(n > 0){
            if(n&1 > 0){
                num_of_ones++;
            }
            n = n>>1;
        }
        return num_of_ones == 1;
    }
};