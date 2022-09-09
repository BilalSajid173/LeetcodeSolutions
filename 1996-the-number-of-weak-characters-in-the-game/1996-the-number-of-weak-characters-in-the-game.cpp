class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
     {
          if (a[0] == b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0;
        sort(properties.begin(), properties.end(), compare);
        int max = properties[properties.size() - 1][1];
        for(int i = properties.size() - 2;i>=0;i--){
            if(properties[i][1] >= max){
                max = properties[i][1];
            }else {
                ans++;
            }
        }
        return ans;
    }
};