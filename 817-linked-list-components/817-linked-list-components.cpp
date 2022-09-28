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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int, int> m;
        for(auto x:nums){
            m[x] = 1;
        }
        
        ListNode* temp = head;
        int cnt = 0;
        bool ongoing = false;
        while(temp != NULL){
            if(m.find(temp->val) != m.end()){
                ongoing = true;
            } else {
                if(ongoing){
                    ongoing = false;
                    cnt++;
                }
            }
            temp = temp->next;
        }
        if(ongoing) cnt++;
        return cnt;
    }
};