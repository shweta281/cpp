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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s(nums.begin(), nums.end());
        while(head && s.find(head->val)!=s.end()) head=head->next;
        ListNode* ans=head;
        ListNode* dummy=head;
        head=head->next;
        while(head){
            if(s.find(head->val)!=s.end()){
                dummy->next=head->next;
            }
            else{
                dummy=dummy->next;
            }
            head=head->next;
        }
        return ans;
    }
};
