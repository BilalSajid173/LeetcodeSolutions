/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        if(head->child){
            Node* temp = flatten(head->child);
            Node* temp1 = flatten(head->next);
            Node* temp2 = temp;
            while(temp2->next != NULL){
                temp2 = temp2->next;
            }
            head->next = temp;
            temp->prev = head;
            temp2->next = temp1;
            if(temp1)
            temp1->prev = temp2;
            head->child = NULL;
            return head;
        }
        head->next = flatten(head->next);
        return head;
        
    }
};