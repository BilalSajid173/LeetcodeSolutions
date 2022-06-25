/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast != NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                break;
            }
        }
        if(fast == NULL or fast->next == NULL)
            return NULL;
        while(slow != fast)
        {
            slow = slow ->next;
            fast = fast->next;
        }
        return slow;
    }
};