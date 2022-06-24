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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0,head);
    ListNode *previous = dummy, *current = head;
    
    while(current) {
        ListNode *next_node = current->next;
        while(next_node && current->val == next_node->val) {
            ListNode *temp = next_node->next;
            delete next_node;
            next_node = temp;
        }
        
        if(current->next == next_node) {
            previous = current;
        } else {
            previous->next = next_node;
            delete current;
        }
        current =  next_node;
    }
    
    return dummy->next;
}
};
    
//     Recursive solution
    
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (!head) return 0;
//         if (!head->next) return head;
        
//         int val = head->val;
//         ListNode* p = head->next;
        
//         if (p->val != val) {
//             head->next = deleteDuplicates(p);
//             return head;
//         } else {
//             while (p && p->val == val) p = p->next;
//             return deleteDuplicates(p);
//         }
//     }