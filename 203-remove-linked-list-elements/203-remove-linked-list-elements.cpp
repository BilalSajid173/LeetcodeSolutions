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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head)
            return head;
        
        ListNode * dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode * temp = head;
        while(temp){
            ListNode* next_node = temp->next;
            if(temp->val == val){
                delete temp;
                prev->next = next_node;
            }
            else{
                prev = temp;
            }
            temp = next_node;
        }
        return dummy->next;
    }
};