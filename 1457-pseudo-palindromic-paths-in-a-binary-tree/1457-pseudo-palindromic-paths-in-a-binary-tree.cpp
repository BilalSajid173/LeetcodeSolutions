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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        v[0] = 0;
        return helper(v,root);
    }
    
    int helper(vector<int> v, TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            v[root->val]++;
            int cnt = 0;
            for(int i = 1;i<v.size();i++){
                if(v[i]%2 != 0) cnt++;
            }
            return cnt <= 1 ? 1 : 0;
        }
        
        v[root->val]++;
        int left = helper(v, root->left);
        int right = helper(v,root->right);
        return left + right;
    }
};