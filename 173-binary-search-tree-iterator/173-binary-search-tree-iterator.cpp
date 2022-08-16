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
class BSTIterator {
public:
    vector<int> nodes;
    int i = 0;
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
    }
    
    int next() {
        return nodes[i++];
    }
    
    bool hasNext() {
        if((i < nodes.size())) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */