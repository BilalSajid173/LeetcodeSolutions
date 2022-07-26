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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return ans.second;
    }
    
    pair<int,int> helper(TreeNode* root){
        pair<int,int> p;
        if(root == NULL){
            p.first = 0;
            p.second = 0;
            return p;
        }
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        p.first = max(left.first, right.first) + 1;
        p.second = max((left.first + right.first), max(left.second, right.second));
        return p;
    }
};