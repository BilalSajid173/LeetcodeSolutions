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
    string tree2str(TreeNode* root) {
        if(root == NULL){
            return "()";
        }
        string left = "", right ="";
        if(root->left){
            left = tree2str(root->left);
        }
        if(root->right){
            right = tree2str(root->right);
        }
        string ans = to_string(root->val);
        if(right != "")
        ans = to_string(root->val) + "(" + left + ")" + "(" + right + ")";
        if(right == "" && left != ""){
            ans = to_string(root->val) + "(" + left + ")";
        }
        return ans;
    }
};