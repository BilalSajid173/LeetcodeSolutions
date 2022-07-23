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
    int height(TreeNode *root) {
         if (root == NULL)
           {
              return 0;
           }
         int leftheight = height(root->left);
         int rightheight = height(root->right);
         return max(leftheight, rightheight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }
        int lefth = 0, righth = 0;
        lefth = height(root->left);
        righth = height(root->right);
        if((lefth - righth) > 1 || (righth - lefth) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};