class KthLargest {
public:
    multiset<int> ans;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        ans.insert(nums.begin(), nums.end());
    }
    
    int add(int val) {
        ans.insert(val);
        auto it = ans.begin();
        int len = ans.size() - k;
        int i = 0;
        while(i<len){
            it++;
            i++;
        }
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */