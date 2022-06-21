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
    bool checkBST(TreeNode* root,long min = LONG_MIN, long max = LONG_MAX){
        if(root == NULL){
            return true;
        }
        
        
        if(root->val > min && root->val< max && checkBST(root->left,min,root->val) && checkBST(root->right,root->val,max)){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root);
    }
};