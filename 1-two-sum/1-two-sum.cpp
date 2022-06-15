class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        int n = nums.size();
        vector<pair<int,int>> v; 
        for(int i = 0; i<n;i++){
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            if((v[i].first + v[j].first)>target)
            {
                j--;
            }
            else if((v[i].first + v[j].first)<target)
            {
                i++;
            }
            else if((v[i].first + v[j].first)==target)
            {
                answer.push_back(v[i].second);
                answer.push_back(v[j].second);
                break;
            }
        }
        return answer;
    }
};