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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m, vector<int>(n, -1));
        int up=0, left=0, right=n-1, down=m-1;
        int count=m*n;
        while(count>0 && head){
            for (int i=left; i<=right; i++){
                if(!head || count<=0) break;
                ans[up][i]=head->val;
                head=head->next;
                count--;
            }
            up++;
            for (int i=up; i<=down; i++){
                if(!head || count<=0) break;
                ans[i][right]=head->val;
                head=head->next;
                count--;
            }
            right--;
            for (int i=right; i>=left; i--){
                if(!head || count<=0) break;
                ans[down][i]=head->val;
                head=head->next;
                count--;
            }
            down--;
            for (int i=down; i>=up; i--){
                if(!head || count<=0) break;
                ans[i][left]=head->val;
                head=head->next;
                count--;
            }
            left++;
        }
        return ans;
    }
};
