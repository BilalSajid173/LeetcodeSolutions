class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        
        // vector<string> powers;
        for(int i = 0;i<= 30;i++){
            int p = pow(2,i);
            string x = to_string(p);
            sort(x.begin(), x.end());
            // powers.push_back(x);
            if(x == s) return true;
        }
        return false;
    }
};