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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* less = dummy;
        ListNode* more = dummy;
        while(less->next && less->next->val < x){
            less = less->next;
        }
        more = less->next;
        if(!more) return dummy->next;
        ListNode* temp = more->next;
        while(temp){
            if(temp->val < x){
                ListNode* temp1 = less->next;
                less->next = temp;
                more->next = temp->next;
                temp->next = temp1;
                less = temp;
                temp = more->next;
            } else if(temp->val >= x){
                more = temp;
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};