class Solution {
public:
    static bool compare(vector<int> p1, vector<int> p2){
        return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),compare);
        vector<vector<int>> ans;
        vector<int> temp;
        temp = intervals[0];
        for(int i = 1;i<(int)intervals.size();i++){
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(temp[1],intervals[i][1]);
            } else {
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};