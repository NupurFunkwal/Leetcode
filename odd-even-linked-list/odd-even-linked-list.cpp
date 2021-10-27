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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        
        ListNode* dummy_odd = new ListNode(-1), *dummy_even = new ListNode(-1);
        ListNode *odd = dummy_odd, *even = dummy_even;
        ListNode *curr = head;
        int turn = 1;
        
        while(curr){
            if(turn == 1){
                odd->next = curr;
                odd = odd->next;
                turn = 0;
                curr = curr->next;
                odd->next = NULL;
            }
            else if(turn == 0){
                even->next = curr;
                even = even->next;
                turn = 1;
                curr = curr->next;
                even->next = NULL;
            }
        }
        
        odd->next = dummy_even->next;
        return dummy_odd->next;
    }
};