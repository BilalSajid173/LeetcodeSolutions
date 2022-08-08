class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0], l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            l =  (l) * nums[i];
            r =  (r) * nums[n - 1 - i];
            res = max(res, max(l, r));
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return res;
        
        //M-2
//         // Return early if input is empty
//         if (nums.empty()) return 0;
		
//         int best = INT_MIN;
//         // Running products
//         int maxProd = 1;
//         int minProd = 1;
        
//         for (int n: nums) {
//             if (n < 0) {
//                 // Swap max and min
//                 swap(maxProd, minProd);
//             }
//             // Reset to current value if smaller or larger than it
//             // (intuitively means that we start considering a new sub-array)
//             maxProd = max(maxProd*n, n);
//             minProd = min(minProd*n, n);
//             // Update the best
//             best = max(best, maxProd);
//         }
        
//         return best;
    }
};