bool cmp(vector<int> a, vector<int> b) {
    if(a[1] < b[1]) {
        return true;
    }
    return false;
}

class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp); //sort the list

        //initialization
        int count = 1;
        int cur = pairs[0][1]; 

        for(int i=1; i<n; i++) {           
            if(cur < pairs[i][0]) { //b<c
                cur = pairs[i][1];
                count++;
            }
        }
        return count;
    }
};