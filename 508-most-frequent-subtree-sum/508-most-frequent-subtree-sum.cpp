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
    map<int,int> fre;
    int maxfre = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int x = helper(root);
        vector<int> ans;
        for(auto a:fre){
            if(a.second == maxfre) ans.push_back(a.first);
        }
        return ans;
    }
    
    int helper(TreeNode* root){
        if(!root) return 0;
        
        
        int left = helper(root->left);
        int right = helper(root->right);
        int sum = left + right + root->val;
        fre[sum]++;
        root->val = sum;
        if(fre[sum] > maxfre) maxfre = fre[sum];
        return root->val;
        
    }
};