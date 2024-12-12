class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long ans = 0;
        while(k > 0){
            int curr = pq.top();
            pq.pop();
            k--;
            pq.push(floor(sqrt(curr)));
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
