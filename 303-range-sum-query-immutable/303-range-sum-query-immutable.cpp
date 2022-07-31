class NumArray {
public:
    vector<int> num;
    NumArray(vector<int>& nums) {
        num.push_back(0);
        for( auto val : nums){
            num.push_back(num.back() + val);
        }
   }
    
    int sumRange(int left, int right) {
        return num[right + 1] - num[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */