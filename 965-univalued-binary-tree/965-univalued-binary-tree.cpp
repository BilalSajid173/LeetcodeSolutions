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
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        int x = root->val, y = root->val;
        bool left = true, right = true;
        if(root->left){
            x = root->left->val;
            left = isUnivalTree(root->left);
        }
        if(root->right){
            y = root->right->val;
            right = isUnivalTree(root->right);
        }
        return root->val == x && root->val == y && left && right;
    }
};