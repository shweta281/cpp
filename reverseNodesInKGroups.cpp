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
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        if(length(temp)>=k){
            //reverse
            ListNode* prev=NULL;
            int count=0;
            while(count<k){
                ListNode* temp1=temp->next;
                temp->next=prev;
                prev=temp;
                temp=temp1;
                count++;
            }
            head->next=reverseKGroup(temp, k);
            return prev;
        }
        else{
            return head;
        }
    }
};
