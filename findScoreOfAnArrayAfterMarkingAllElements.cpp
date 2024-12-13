class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> vis(n , -1);
        for (int i = 0; i < n; i++){
            pq.push({-1* nums[i], -1 * i});
        }
        long long ans = 0;
        while(!pq.empty()){
            int curr = -1 * pq.top().first;
            int curr_ind = -1 * pq.top().second;
            pq.pop();
            if(vis[curr_ind] != -1){
                continue;
            }
            ans += curr;
            vis[curr_ind] = 0;
            if(curr_ind - 1 >= 0){
                vis[curr_ind - 1] = 0;
            }
            if(curr_ind + 1 < n){
                vis[curr_ind + 1] = 0;
            }
        }
        return ans;
    }
};
