class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        vector<int> prev;
        vector<int> cur;
        prev.push_back(1);
        ans.push_back(prev);
        numRows--;
        while(numRows){
            int i = 0, j = 1;
            while(j < prev.size()){
                int num= prev[i] + prev[j];
                cur.push_back(num);
                i++;
                j++;
            }
            cur.insert(cur.begin(), 1);
            cur.push_back(1);
            prev = cur;
            ans.push_back(cur);
            cur.clear();
            numRows--;
        }
        return ans;
    }
};