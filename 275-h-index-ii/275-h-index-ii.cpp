class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int s = 0, e = size - 1;
        int ans  = 0;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(size - mid <= citations[mid]){
                ans = size - mid;
                e = mid - 1;
            } else if(size - mid > citations[mid]){
                s = mid + 1;
            } 
        }
        return ans;
    }
};