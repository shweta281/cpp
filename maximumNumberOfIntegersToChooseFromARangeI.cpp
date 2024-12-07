class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(banned.begin(), banned.end());
        int count = 0;
        for (int i = 1; i <= n; i++){
            if(s.find(i) == s.end()){
                if(maxSum - i < 0){
                    break;
                }
                maxSum -= i;
                count++;
            }
        }
        return count;
    }
};
