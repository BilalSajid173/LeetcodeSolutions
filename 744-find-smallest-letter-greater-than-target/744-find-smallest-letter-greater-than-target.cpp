class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int s = 0, e = letters.size() - 1;
        char ans = letters[0];
        while(s <= e){
            int mid = (s + e) / 2;
            if(letters[mid] > target){
                ans = letters[mid];
                e = mid - 1;
            } else if(letters[mid] <= target){
                s = mid + 1;
            }
        }
        return ans;
    }
};