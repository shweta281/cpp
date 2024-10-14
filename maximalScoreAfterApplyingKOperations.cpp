class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        double ans = 0;
        while(k > 0){
            double curr = pq.top();
            pq.pop();
            ans += curr;
            pq.push(ceil(curr / 3));
            k--;
        }
        return ans;
    }
};
