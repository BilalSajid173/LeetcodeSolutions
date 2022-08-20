// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        while(i <= n){
            int mid = i + (n - i) / 2;
            if(!isBadVersion(mid)){
                i = mid + 1;
            }
            else if(isBadVersion(mid)){
                n = mid - 1;
            }
        }
        return i;
    }
};