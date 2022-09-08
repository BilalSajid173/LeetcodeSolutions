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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> todo;
        vector<int> nodes;
        while(root || !todo.empty()){
            while(root){
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }
};