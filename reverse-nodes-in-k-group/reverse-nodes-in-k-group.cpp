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
    ListNode *reverse(ListNode *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *temp = head->next;
        head->next = NULL;
        ListNode *newhead = reverse(temp);
        temp->next = head;
        return newhead;      
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1){
            return head;
        }
        
        ListNode *p = head,*q=head;
        for(int i=1; i<k;i++){
            if(q == NULL){
                break;
            }
            q = q->next;
        }
        if(q == NULL){
            return head;
        }
        else{
            ListNode *temp = q->next;
            q->next = NULL;
            ListNode *finalhead = reverse(p);
            ListNode *newhead = reverseKGroup(temp, k);
            p->next = newhead;
            return finalhead;
        }
        
    }
};