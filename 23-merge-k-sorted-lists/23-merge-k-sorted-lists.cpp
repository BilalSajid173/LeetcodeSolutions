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
    typedef pair<int,ListNode*> node;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        
        priority_queue <node, vector<node>, greater<node> > pq;
        for(int i = 0;i< lists.size();i++){
            if(lists[i])
            pq.push({lists[i]->val,lists[i]});
        }
        
        while(!pq.empty()){
            int x = pq.top().first;
            ListNode* y = pq.top().second;
            pq.pop();
            if(head == NULL){
                head = y;
                tail = y;
            } else{
                tail->next = y;
                tail = y;
            }
            if(y->next){
                y = y->next;
                pq.push({y->val,y});
            }
        }
        return head;
    }
};