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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int x = helper(root, targetSum);
        int y = pathSum(root->left, targetSum);
        int z = pathSum(root->right, targetSum);
        return x + y + z;
    }
    
    int helper(TreeNode* root, long long target){
        if(!root) return 0;
        int sum = 0;
        if(target - root->val == 0){
            sum++;
        }
        sum += helper(root->left, target - root->val);
        sum += helper(root->right, target - root->val);
        return sum;
    }
};