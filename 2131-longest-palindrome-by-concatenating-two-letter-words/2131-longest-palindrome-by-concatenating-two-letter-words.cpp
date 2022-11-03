class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m;
        for(auto x:words){
            m[x] += 1;
        }
        int ans = 0;
        int flag = 0;
        for(auto p:m){
            string x = p.first;
            int cnt = p.second;
            string rev(x.rbegin(),x.rend());
            if(rev == x) {
                if(cnt%2==0){
                    ans += 2*cnt;
                }else{
                    if(!flag){
                        ans += cnt*2;
                        flag = 1;
                    } else{
                        ans += (cnt-1)*2;
                    }
                }
            }
            else {
            int cnt2 = m[rev];
            ans += min(cnt, cnt2)*4;
            }
            m[x] = 0;
            m[rev] = 0;
        }
        return ans;
    }
};