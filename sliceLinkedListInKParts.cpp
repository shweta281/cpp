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
    int length(ListNode* head){
        ListNode* node=head;
        int count=0;
        while(node){
            count++;
            node=node->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l=length(head);
        int every=l/k;
        int mod=l%k;
        vector<ListNode*>ans;
        cout<<every<<" "<<mod<<endl;
        while(k>0){
            k--;
            ans.push_back(head);
            int temp=every+(mod>0);
            ListNode* node=head;
            while(node && temp>1){
                node=node->next;
                temp--;
            }
            if(node){
                head=node->next;
                node->next=nullptr;
            }
            
            mod=max(mod-1, 0);
        }
        return ans;
    }
};
