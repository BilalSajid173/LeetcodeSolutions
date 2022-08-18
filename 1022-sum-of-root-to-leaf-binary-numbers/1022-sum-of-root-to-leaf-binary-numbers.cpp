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
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        helper(root, "");
        return sum;
    }
    
    void helper(TreeNode* root, string s){
        if(!root) return;
        if(!root->left && !root->right){
            bintodec(s + to_string(root->val));
            return;
        }
        helper(root->left, s + to_string(root->val));
        helper(root->right, s + to_string(root->val));
    }
    
    void bintodec(string x){
        int a = 1;
        int num = 0;
        for(int i = x.length() - 1;i>=0;i--){
            num += a*(x[i] - '0');
            a *= 2;
        }
        sum += num;
        return;
    }
};