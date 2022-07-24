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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        vector<int> v;
        helper(sum, root, v);
        return sum;
    }
    
    void helper(int &sum, TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        v.push_back(root->val);
        if(!root->left && !root->right){
            long long int num = 0, x = 1;
            for(int i = v.size() - 1; i>=0;i--){
                num += v[i]*x;
                x = x*10;
            }
            sum += num;
        }
        helper(sum, root->left, v);
        helper(sum,root->right, v);
        v.pop_back();
        return;
    }
};