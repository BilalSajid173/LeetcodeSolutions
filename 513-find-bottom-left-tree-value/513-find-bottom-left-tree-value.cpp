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
    int maxlevel = -1;
    int ans = 0;
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return 0;
        ans = root->val;
        helper(root, 0);
        return ans;
    }
    
    void helper(TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        if(maxlevel< level){
            ans = root->val;
            maxlevel = level;
        }
        helper(root->left, level + 1);
        helper(root->right, level + 1);
        return;
    }
};