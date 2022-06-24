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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        
        ListNode* oddtail = head;
        ListNode* evenhead = head->next;
        ListNode* eventail = head->next;
        int count = 3;
        ListNode* cur = evenhead->next;
        ListNode* next = cur;
        
        while(next != NULL){
            next = cur->next;
            if(count % 2 != 0){
                oddtail->next = cur;
                cur->next = evenhead;
                oddtail = cur;
                eventail->next = next;
                cur = next;
            }
            if(count %2 == 0){
                eventail = cur;
                cur = next;
            }
            count++;
        }
        
        return head;
        
    }
};