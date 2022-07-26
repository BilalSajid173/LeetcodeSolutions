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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        if(root->val == subRoot->val){
            bool check = helper(root, subRoot);
            if(check){
                return true;
            }
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool helper(TreeNode* x, TreeNode* y){
        if(!x && !y){
            return true;
        }
        if(!x && y || x && !y){
            return false;
        }
        if(x->val == y->val && helper(x->left, y->left) && helper(x->right, y->right)){
            return true;
        }
        return false;
    }
};