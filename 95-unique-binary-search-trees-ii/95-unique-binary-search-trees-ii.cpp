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
    vector<TreeNode*> alltrees(int s,int e){
        if(s>e)
            return {NULL};
        vector<TreeNode *> left,right,res;
        for(int i = s;i<=e;i++){
            left = alltrees(s,i-1);
            right = alltrees(i+1,e);
            for(auto c:left){
                for(auto d:right){
                    TreeNode* node = new TreeNode(i);
                    node->left = c;
                    node->right = d;
                    res.push_back(node);
                }
            }
            
        }
        return res;
    }
        
    vector<TreeNode*> generateTrees(int n) {
        return alltrees(1,n);
    }
};