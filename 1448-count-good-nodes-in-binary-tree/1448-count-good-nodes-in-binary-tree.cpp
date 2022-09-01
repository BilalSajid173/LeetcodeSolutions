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
    int goodNodes(TreeNode* root) {
        int ans = helper(root, root->val);
        return ans;
    }
    
    int helper(TreeNode* root, int max){
        if(!root) return 0;
        int ans = 0;
        if(root->val >= max){
            ans = 1;
            max = root->val;
        }
        ans += helper(root->left, max);
        ans += helper(root->right, max);
        return ans;
    }
};