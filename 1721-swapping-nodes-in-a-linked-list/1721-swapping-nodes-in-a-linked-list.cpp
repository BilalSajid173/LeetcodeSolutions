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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode * slow = head;
        ListNode *fast = head, *fromstart;
        while(k>1)
        {
            fast = fast->next;
            k--;
        }
        fromstart = fast;
        while(fast ->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        swap(fromstart->val,slow->val);
        return head;
    }
};