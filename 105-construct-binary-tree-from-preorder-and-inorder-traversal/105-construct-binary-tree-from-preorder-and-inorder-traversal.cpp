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
    
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&hmap, int &index, int low, int high ){
        if(index >= preorder.size()){
            return nullptr;
        }
        if(low<=high){
            int currValue = preorder.at(index);
            index++;
            
            int currIndex = hmap[currValue];
                  
            TreeNode *node = new TreeNode(currValue);
            node->left = constructTree(preorder, inorder,hmap, index, low, currIndex-1);
            node->right = constructTree(preorder, inorder,hmap, index, currIndex+1, high);
            return node;
        }
        
        return nullptr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int low = 0, high = preorder.size()-1;
        unordered_map<int,int> inorderIndex;
        for(int i=0; i<inorder.size(); ++i){
            inorderIndex.insert({inorder.at(i), i});
        }
        return constructTree(preorder, inorder,inorderIndex, index, low, high);
        
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map
