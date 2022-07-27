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
    vector<int> v1;
    vector<int> v2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leafnodes(root1, v1);
        leafnodes(root2, v2);
        if(v1 == v2) return true;
        return false;
    }
    
    void leafnodes(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        leafnodes(root->left, v);
        leafnodes(root->right, v);
        return;
    }
};