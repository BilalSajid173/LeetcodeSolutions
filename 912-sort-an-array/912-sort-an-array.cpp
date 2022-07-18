class Solution {
public:
    void buildheap(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int idx = i;
        int parent = i / 2;
        while (idx > 0 && v[idx] > v[parent]) // making a max heap
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

    
    void heapify(vector<int> &nums, int idx, int size){
        int left = 2 * idx;
        int right = left + 1;
        int last = size - 1;
        int minidx = idx;
        if(left<=last && (nums[left] > nums[idx]))
        {
            minidx = left;
        }
        if(right<=last && (nums[right] > nums[minidx]))
        {
            minidx = right;
        }
        if(minidx != idx){
            swap(nums[idx], nums[minidx]);
            heapify(nums,minidx,size);
        }
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        buildheap(nums);
        int n = nums.size();
        while(n>0){
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums, 0, n);
        }
        
        return nums;
    }
};