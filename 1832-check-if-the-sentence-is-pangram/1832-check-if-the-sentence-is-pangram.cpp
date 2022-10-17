class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26, 0);
        int cnt = 0;
        for(auto c : sentence){
            if(v[int(c) - 97] == 0){
                v[int(c) - 97] = 1;
                cnt++;
                if(cnt == 26) return true;
            }
        }
        return false;
    }
};