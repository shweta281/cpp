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

    struct compare{
        bool operator()( ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unordered_map<int,int>map;
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for (int i=0; i<lists.size(); i++){
            if(lists[i]==nullptr) continue;
            pq.push({lists[i]});
        }
        ListNode* ans= new ListNode;
        ListNode* temp=ans;
        while(pq.empty()!=true){
            ListNode* head= pq.top();
            pq.pop();
            ans->next=head;
            head=head->next;
            ans=ans->next;
            if(head)
                pq.push(head);
        }
        return temp->next;
    }
};
