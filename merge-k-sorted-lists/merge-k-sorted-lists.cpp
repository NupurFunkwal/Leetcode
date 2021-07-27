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
    struct comp{
        bool operator()(const pair<int,ListNode*> &a, const pair<int,ListNode*> &b){
            return a.first > b.first;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0){
            return NULL;
        }
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, comp> pq;
        for(int i=0; i<k; i++){
            if(lists[i] != NULL){
                pq.emplace(make_pair(lists[i]->val, lists[i]));
            }
        }
        
        if(pq.size() == 0){
            return NULL;
        }
        
        ListNode* head = pq.top().second;
        ListNode *temp = head;
        pq.pop();
        if(temp->next != NULL){
            pq.emplace(make_pair(temp->next->val, temp->next));   
        }
        
        while(!pq.empty()){
            temp->next = pq.top().second;
            pq.pop();
            temp = temp->next;
            if(temp->next!=NULL){
                pq.emplace(make_pair(temp->next->val, temp->next));
            }
        }
        
        return head;
        
    }
};