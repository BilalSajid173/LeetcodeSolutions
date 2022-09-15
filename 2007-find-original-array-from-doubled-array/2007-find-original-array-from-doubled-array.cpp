class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {};
        sort(changed.begin(),changed.end());
        map<int, int> m;
        for(int i = 0;i<changed.size();i++){
            m[changed[i]]++;
        }
        
        vector<int>ans;
        for(auto x:changed){
            if(x == 0){
                if(m[x] > 1){
                    ans.push_back(x);
                    m[x]-=2;
                }
            }
            // if(m[x] == 1 && m.find(2*x) != m.end()){
            //     ans.push_back(x);
            //     m[2*x] = 0;
            // }
            else if(m[x] > 0 && m.find(2*x) != m.end() && m[2*x] > 0){
                ans.push_back(x);
                m[x]--;
                m[2*x]--;
            }
        }
        
        if(ans.size() == changed.size()/2) return ans;
        return {};
    }
};