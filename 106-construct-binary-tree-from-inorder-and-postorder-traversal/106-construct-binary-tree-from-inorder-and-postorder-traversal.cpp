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
    int postpointer;
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postpointer = postorder.size() - 1;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, (inorder.size() - 1));
        
    }
    TreeNode* helper(vector<int> inorder, vector<int> postorder,int s, int e){
        if(s>e){
            return NULL;
        }
        int idx = mp[postorder[postpointer]];
        TreeNode * root = new TreeNode(postorder[postpointer]);
        postpointer--;
        root->right = helper(inorder, postorder, idx + 1, e);
        root->left = helper(inorder, postorder, s,idx - 1);
        return root;
    }
    
};