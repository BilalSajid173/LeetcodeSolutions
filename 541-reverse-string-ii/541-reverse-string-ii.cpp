class Solution {
public:
    string reverseStr(string s, int k) {
        if(k == 1) return s;
        int n = s.size();
        int left = 0;
        for(int i = 0; i < n; i++){
            if((n-i) >= (2*k)){
                int right = i + k - 1;
                while(left <= right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                i += (2 * k) - 1;
                left = i + 1;
            }
            else if((n-i) >= k && (n-i) < (2*k)){
                int right = i + k - 1;
                while(left <= right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                return s;
            } else if((n-i) < k) {
                int right = n-1;
                while(left <= right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                return s;
            }
        }
        return s;
    }
};