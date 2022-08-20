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
    int ans;
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        int x = helper(root);
        return ans;
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int leftans = 0, rightans = 0;
        if(root->left && root->left->val == root->val)
            leftans += left + 1;
        if(root->right && root->right->val == root->val)
            rightans += right + 1;
        ans = max(ans, (leftans+rightans));
        return max(leftans, rightans);
    }
    
};