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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL){
            return NULL;
        }
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        } 
        else if(key == root->val){
            if(!root->right && !root->left){
                delete root;
                return NULL;
            }
            if(root->left && !root->right){
                TreeNode * temp = root->left;
                delete root;
                return temp;
            }
            if(root->right && !root->left){
                TreeNode * temp = root->right;
                delete root;
                return temp;
            }
            TreeNode * temp = root->right;
            while(temp->left){
                    temp = temp->left;
            }
            int t = root->val;
            root->val = temp->val;
            temp->val = t;
            root->right = deleteNode(root->right, key);
            return root;
        }
        
    return NULL;
    }
};