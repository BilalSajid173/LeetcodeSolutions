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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;
        while(temp){
            ListNode*temp1 = temp;
            while(temp1 && temp1->val <= temp->val){
                temp1 = temp1->next;  
            }
            if(temp1){
                ans.push_back(temp1->val);
            } else {
                ans.push_back(0);
            }
            temp = temp->next;
        }
        return ans;
    }
};