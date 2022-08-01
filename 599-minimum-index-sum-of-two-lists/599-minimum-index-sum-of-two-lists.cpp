class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> m;
        for(int i = 0;i<list1.size();i++){
            m[list1[i]] = i;
        }
        int sum = INT_MAX;
        vector<string> ans;
        for(int i = 0;i<list2.size();i++){
            if(m.count(list2[i])){
                int x = i + m[list2[i]];
                if(x == sum){
                    ans.push_back(list2[i]);
                } else if(x < sum){
                    sum = x;
                    ans.clear();
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};