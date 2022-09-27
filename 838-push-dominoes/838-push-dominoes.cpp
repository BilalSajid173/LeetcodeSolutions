class Solution {
public:
    string pushDominoes(string s) {
        vector<pair<int,int>> left;
        vector<pair<int,int>> right;
        int rc = 0, lc = 0;
        int rsec = 1, lsec = 1;
        for(auto c:s){
            if(c == '.'){
                if(rc == 1){
                    right.push_back({rc, rsec});
                    rsec++;
                } else {
                    right.push_back({-1,-1});
                }
            } else if(c == 'R'){
                rc = 1;
                rsec = 1;
                right.push_back({-1,-1});
            } else if(c == 'L'){
                rc = 0;
                rsec = 1;
                right.push_back({-1,-1});
            }
        }
        for(int i = s.size() - 1;i>=0;i--){
            if(s[i] == '.'){
                if(lc == 1){
                    left.push_back({lc, lsec});
                    lsec++;
                } else {
                    left.push_back({-1,-1});
                }
            } else if(s[i] == 'L'){
                lc = 1;
                lsec = 1;
                left.push_back({-1,-1});
            } else if(s[i] == 'R'){
                lc = 0;
                lsec = 1;
                left.push_back({-1,-1});
            }
        }
        reverse(left.begin(), left.end());
        string ans = "";
        for(int i = 0;i<s.size();i++){
            if(left[i].first == -1 && right[i].first == -1){
                ans += s[i];
            } else if(left[i].first != -1 && right[i].first == -1){
                ans += 'L';
            }
            else if(left[i].first == -1 && right[i].first != -1){
                ans += 'R';
            } else if(left[i].first != -1 && right[i].first != -1){
                if(left[i].second > right[i].second){
                    ans += 'R';
                } else if(left[i].second < right[i].second){
                    ans += 'L';
                } else {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};