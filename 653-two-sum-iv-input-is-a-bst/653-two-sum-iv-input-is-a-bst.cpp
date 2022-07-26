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
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        stack<TreeNode*> todo;
        vector<int> v;
        while(root || !todo.empty()){
            while(root){
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            v.push_back(root->val);
            todo.pop();
            root = root->right;
        }
        int s = 0, e = v.size() -1;
        while(s<e){
            if((v[s] + v[e]) < k){
                s++;
            } else if((v[s] + v[e]) >k){
                e--;
            } else if((v[s] + v[e]) == k){
                return true;
            }
        }
        return false;
    }
};