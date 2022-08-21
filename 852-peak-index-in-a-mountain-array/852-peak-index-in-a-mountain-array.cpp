class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 1, e = arr.size() - 2;
        while(s <= e){
            int mid = (s + e) / 2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return mid;
            } else if(arr[mid] > arr[mid + 1]){
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return 0;
    }
};