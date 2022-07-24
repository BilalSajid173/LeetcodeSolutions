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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        vector<int> level;
        
        if(!root)
            return answer;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
            if(temp == NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                answer.push_back(level);
                    level.resize(0);
            }
            else{
                level.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};