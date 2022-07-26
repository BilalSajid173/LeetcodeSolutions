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
    int height = 1;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root){
            return NULL;
        }
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        if(depth - 1 == height){
            TreeNode*left = root->left;
            TreeNode*right = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = left;
            root->right->right = right;
            return root;
        }
        height++;
        TreeNode* left = addOneRow(root->left, val, depth);
        TreeNode* right = addOneRow(root->right, val,depth);
        height--;
        return root;
    }
};