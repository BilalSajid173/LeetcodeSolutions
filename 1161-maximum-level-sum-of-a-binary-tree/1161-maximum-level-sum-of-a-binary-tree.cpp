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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int maxlevel = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = INT_MIN, cur_ls = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                if(cur_ls > sum){
                    sum = cur_ls;
                    maxlevel = level;
                }
                cur_ls = 0;
                level++;
            }
            else {
                cur_ls += temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return maxlevel;
    }
};