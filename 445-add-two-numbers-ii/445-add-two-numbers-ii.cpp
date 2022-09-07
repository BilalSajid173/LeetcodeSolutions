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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        } 
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* ans = NULL;
        while(!s1.empty() && !s2.empty()){
            int x = s1.top();
            s1.pop();
            int y = s2.top();
            s2.pop();
            int total = x + y + carry;
            carry = total / 10;
            total = total % 10;
            ListNode* dummy = new ListNode(total);
            dummy->next = ans;
            ans = dummy;
        }
        while(!s1.empty()){
            int x = s1.top();
            s1.pop();
            int total = x + carry;
            carry = total / 10;
            total = total % 10;
            ListNode* dummy = new ListNode(total);
            dummy->next = ans;
            ans = dummy;
        }
        while(!s2.empty()){
            int x = s2.top();
            s2.pop();
            int total = x + carry;
            carry = total / 10;
            total = total % 10;
            ListNode* dummy = new ListNode(total);
            dummy->next = ans;
            ans = dummy;
        }
        if(carry){
            ListNode* dummy = new ListNode(carry);
            dummy->next = ans;
            ans = dummy;
        }
        return ans;
    }
};