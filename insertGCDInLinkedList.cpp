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
//10, 6
//6, 4
//4, 2
//2, 0
    int getGCD(int a, int b){
        if(b==0) return a;
        return getGCD(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans=head;
        while(head){
            if(head->next){
                // cout<<getGCD(head->val, head->next->val)<<endl;
                ListNode* knew= new ListNode(getGCD(head->val, head->next->val));
                knew->next=head->next;
                head->next=knew;
                head=knew->next;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
