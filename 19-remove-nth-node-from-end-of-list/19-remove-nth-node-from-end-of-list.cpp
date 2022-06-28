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
    int Length(struct ListNode* p)
    {
        int l=0;
        while(p)
        {
            p=p->next;
            l++;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int diff = Length(head) - n;
        if(diff == 0) return head->next;
        struct ListNode *ptr = head;
        for(int i=0;i<diff-1;i++) ptr=ptr->next;
        ptr->next=ptr->next->next;
        return head;
    }
};