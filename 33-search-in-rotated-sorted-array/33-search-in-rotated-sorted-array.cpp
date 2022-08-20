class Solution {
public:
    int search(vector<int>& nums, int target) {
        
//another solution using inf and -inf
        int start = 0, end = nums.size() - 1;
        
        while(start<= end){
            int mid = start + (end - start) / 2;
            int comparator = nums[mid];
            if((nums[mid] < nums[0] && target < nums[0]) || (nums[mid] >= nums[0] && target >= nums[0])){
                comparator = nums[mid];
            } else {
                if(target >= nums[0]) comparator = INT_MAX;
                else comparator = INT_MIN;
            }
            if(target > comparator) start = mid +1;
            else if(target < comparator) end = mid - 1;
            else if(target == comparator) return mid;
        }
        return -1;
        
        
//         int start = 0,end = nums.size() - 1, ans = -1, mid;
        
//         while(start<=end)
//         {
//             mid = (start + end)/2;
//             if(nums[mid] == target)
//             {
//                 ans = mid;
//                 break;
//             }
//             else if(nums[start] <= nums[mid])
//             {
//                 if(nums[start] <= target and target <= nums[mid])
//                     end = mid-1;
//                 else
//                     start = mid+1;
//             }
//             else if(nums[end] > nums[mid])
//             {
//                 if(nums[mid] <= target and target <= nums[end])
//                     start = mid+1;
//                 else
//                     end = mid -1;
//             }
//         }
//         return ans;
        
    }
};