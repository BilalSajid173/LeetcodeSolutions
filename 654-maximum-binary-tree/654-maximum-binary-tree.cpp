/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int>&nums, int s, int e){
        if(s>e){
            return NULL;
        }
        int maxi = INT_MIN;
        int idx = -1;
        int i = s;
        while(i<=e){
            if(nums[i]>maxi){
                maxi = nums[i];
                idx = i;
            }
            i++;
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = helper(nums, s, idx - 1);
        root->right = helper(nums, idx + 1, e);
        return root;
    }
};