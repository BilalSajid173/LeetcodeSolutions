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
    int getDecimalValue(ListNode* head) {
        int len = length(head);
        len--;
        int num = 0;
        while(head){
            if(head->val == 1){
                int x = fastpower(2,len);
                num += x;
            }
            head = head->next;
            len--;
        }
        return num;
    }
    
    int length(ListNode*head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    
    int fastpower(int x,int y){
        if(y==1){
            return x;
        }
        if(y==0) return 1;
        int ans = fastpower(x, y/2);
        if(y%2 != 0){
            return ans *ans * x;
        }
        return ans*ans;
    }
};