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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return 0;
        set<int> s;
        stack<TreeNode*> todo;
        while(root || !todo.empty()){
            while(root){
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            s.insert(root->val);
            root = root->right;
        }
        auto it = s.begin();
        if(s.size() == 1){
            return -1;
        }
        it++;
        return *it ;
    }
};