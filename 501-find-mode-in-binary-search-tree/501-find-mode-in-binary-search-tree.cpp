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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> fre;
        stack<TreeNode*> todo;
        while(root || !todo.empty()){
            while(root){
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            fre[root->val]++;
            root=root->right;
        }
        vector<int> v;
        int flag = 0;
        for(auto m:fre){
            if(m.second > flag){
                flag = m.second;
                v.clear();
                v.push_back(m.first);
            }
            else if(m.second == flag){
                v.push_back(m.first);
            }
        }
        return v;
    }
};