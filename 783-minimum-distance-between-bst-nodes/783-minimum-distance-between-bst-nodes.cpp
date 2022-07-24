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
    int minDiffInBST(TreeNode* root) {
        if(root == NULL){
            return INT_MAX;
        }
        int op1 = INT_MAX, op2 = INT_MAX;
        if(root->left){
            TreeNode * replace = root->left;
            while(replace->right){
                replace = replace->right;
            }
            op1 = root->val - replace->val;
        }
        if(root->right){
            TreeNode * replace = root->right;
            while(replace->left){
                replace = replace->left;
            }
            op2 = replace->val - root->val;
        }
        return min(min(op1,op2), min(minDiffInBST(root->left),minDiffInBST(root->right)));
    }
};