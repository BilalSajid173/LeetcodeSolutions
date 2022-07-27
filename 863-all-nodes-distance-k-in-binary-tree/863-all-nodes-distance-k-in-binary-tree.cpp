/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> allnodes;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int x = helper(root, target->val, k);
        return allnodes;
    }
    
    void kthLevel(TreeNode* node, int k){
        if(node == NULL || k < 0){
            return;
        }
        if( k == 0){
            allnodes.push_back(node->val);
        }
        kthLevel(node->left, k-1);
        kthLevel(node->right, k-1);
    }
    
    int helper(TreeNode* root, int target, int k){
        if(root == NULL){
            return -1;
        }
        if(root->val == target){
            kthLevel(root,k);
            return 0;
        }
        int left = helper(root->left, target, k);
        if( left != -1){
            if(left + 1 == k){
                allnodes.push_back(root->val);
            } else {
                kthLevel(root->right, k - 2 - left);
            }
            return left + 1;
        }
        int right = helper(root->right, target, k);
        if( right != -1){
            if(right + 1 == k){
                allnodes.push_back(root->val);
            } else {
                kthLevel(root->left, k - 2 - right);
            }
            return right + 1;
        }
        return -1;
    }
};