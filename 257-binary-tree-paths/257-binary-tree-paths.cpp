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
        helper(root, ans);
        return ans;
    }
    
    
    void helper(TreeNode * root, vector<string> &ans){
        if(root == NULL){
            return;
        }
        path += to_string(root->val) + "->";
        if(!root->left && !root->right){
            string str = path.substr(0, path.length() - 2);
            ans.push_back(str);
        }
        helper(root->left, ans);
        helper(root->right, ans);
        int x = to_string(root->val).length();
        path = path.substr(0, path.length() - 2 - x);
        return;
    }
};