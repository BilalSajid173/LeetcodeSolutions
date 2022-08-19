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
    int bestToRoot(TreeNode* root, int& bestOverall) {
        if (!root) return 0;
        auto left = max(0, bestToRoot(root->left, bestOverall));
        auto right = max(0, bestToRoot(root->right, bestOverall));
        // update the best overall value to be the max path including contributions from both sides
        bestOverall = max(bestOverall, root->val + left + right);
        // return the max of the path from the left and the path from the right
        return max(root->val + left, root->val + right);
    }
public:
    int maxPathSum(TreeNode* root) {
        auto bestOverall = numeric_limits<int>::min();
        bestToRoot(root, bestOverall);
        return bestOverall;
    }
};
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         return helper(root).second;
//     }
    
//     pair<int,int> helper(TreeNode* root){
//         if(root == NULL){
//             pair<int,int> p;
//             p.first = 0;
//             p.second = INT_MIN;
//             return p;
//         }
//         pair<int, int> left = helper(root->left);
//         pair<int,int> right = helper(root->right);
//         int op1 = root->val;
//         int op2 = root->val + left.first;
//         int op3 = root->val + right.first;
//         int op4 = root->val + right.first + left.first;
//         int cur_max_sum = max(max(op1,op2), max(op3,op4));
//         int max_branch_sum = max(op1, max(op2,op3));
//         int maxi_path_sum = max(cur_max_sum, max(left.second, right.second));
//         pair<int, int> ans;
//         ans.first = max_branch_sum;
//         ans.second = maxi_path_sum;
//         return ans;
//     }
// };