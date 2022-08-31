/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // vector<int> nextLargerNodes(ListNode* head) {
    //     ListNode* temp = head;
    //     vector<int> ans;
    //     while(temp){
    //         ListNode*temp1 = temp;
    //         while(temp1 && temp1->val <= temp->val){
    //             temp1 = temp1->next;  
    //         }
    //         if(temp1){
    //             ans.push_back(temp1->val);
    //         } else {
    //             ans.push_back(0);
    //         }
    //         temp = temp->next;
    //     }
    //     return ans;
    // }
    //stack solution
    vector<int> nextLargerNodes(ListNode* h) {
  vector<int> res, stack;
  for (auto p = h; p != nullptr; p = p->next) res.push_back(p->val);
  for (int i = res.size() - 1; i >= 0; --i) {
    auto val = res[i];
    while (!stack.empty() && stack.back() <= res[i]) stack.pop_back();
    res[i] = stack.empty() ? 0 : stack.back();
    stack.push_back(val);
  }
  return res;
}
};