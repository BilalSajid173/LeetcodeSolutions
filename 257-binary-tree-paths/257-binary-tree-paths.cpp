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
    string path;
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL){
            return ans;
        }
        helper(root, to_string(root->val), ans);
        return ans;
    }
    
    
    void helper(TreeNode * root, string path, vector<string> &ans){
        if(!root->left && !root->right){
            ans.push_back(path);
        }
        if (root->left != NULL)
            helper(root->left, path + "->" + to_string(root->left->val), ans);
        if (root->right != NULL)
            helper(root->right, path + "->" + to_string(root->right->val), ans);
        
        return;
    }
};