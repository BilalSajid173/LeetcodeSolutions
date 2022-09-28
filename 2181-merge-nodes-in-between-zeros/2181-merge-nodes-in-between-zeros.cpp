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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* temp = head->next;
        ListNode* cur = head->next;
        while(temp){
            if(temp->val != 0){
                sum += temp->val;
                temp = temp->next;
            } else {
                cur->val = sum;
                sum = 0;
                cur->next = temp->next;
                cur = cur->next;
                temp = cur;
            }
        }
        return head->next;
        
    }
};