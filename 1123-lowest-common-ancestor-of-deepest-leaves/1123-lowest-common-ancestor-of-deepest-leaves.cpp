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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if ( !root || !root->left && !root->right ) return root;
        TreeNode *leftMost = NULL;
        TreeNode *rightMost = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ) {
            int levelSize = q.size();
            for(int level = 0; level < levelSize; level++ ) {
                TreeNode* node = q.front(); q.pop();
                if ( level == 0 ) leftMost = node;
                if ( level == levelSize - 1 ) rightMost = node;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
        }
        return lca(root, leftMost->val,rightMost->val);
    }
    
    TreeNode* lca(TreeNode* root, int a, int b){
        if(!root) return NULL;
        if (root->val == a || root->val == b)
        {
              return root;
        }
        TreeNode* left = lca(root->left, a, b);
        TreeNode * right = lca(root->right, a, b);
        if(left && right){
            return root;
        }
        if(left){
            return left;
        }
        return right;

    }
};