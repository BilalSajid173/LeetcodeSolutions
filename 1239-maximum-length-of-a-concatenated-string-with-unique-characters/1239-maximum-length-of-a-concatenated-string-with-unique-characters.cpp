class Solution {
public:
    int maxLength(vector<string>& arr) {
        return helper(arr, "", 0);
    }
    
    int helper(vector<string> arr, string s, int i){
        if(i==arr.size()){
            return s.length();
        }
        string a = s;
        int flag = 1;
        for(auto x:arr[i]){
            if(a.find(x) != string::npos){
                flag = 0;
                break;
            } else{
                a += x;
            }
        }
        int include = 0;
        if(flag){
            include = helper(arr, a, i + 1);
        }
        int exclude = helper(arr, s, i+1);
        return max(include, exclude);
    }
};