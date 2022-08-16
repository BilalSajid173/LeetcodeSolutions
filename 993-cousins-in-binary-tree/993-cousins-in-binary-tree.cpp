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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int c= 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(c == 2) return true;
                if(c == 1) return false;
                if(!q.empty()) q.push(NULL);
            } else{
                if(temp->left && temp->right){
                    if((temp->left->val == x && temp->right->val == y) || (temp->left->val == y && temp->right->val == x)) return false;
                }
                if(temp->left){
                    if(temp->left->val == x || temp->left->val == y) c++;
                }
                if(temp->right){
                    if(temp->right->val == x || temp->right->val == y) c++;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return false;
    }
        
};