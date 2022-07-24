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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allpaths;
        vector<int> path;
        findAllPaths(root, targetSum, allpaths,path);
        return allpaths;
    }
    
    void findAllPaths(TreeNode * root, int sum, vector<vector<int>> &allpaths, vector<int> &path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        if(!root->left && !root->right && (sum - root->val) == 0){
            allpaths.push_back(path);
        }
        findAllPaths(root->left, sum - root->val, allpaths, path);
        findAllPaths(root->right, sum - root->val, allpaths, path);
        path.pop_back();
        return;
    }
};