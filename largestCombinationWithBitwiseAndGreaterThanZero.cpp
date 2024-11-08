class Solution {
public:
    int largestCombination(vector<int>& can) {
        int ans = 0;
        unordered_map<int, int> len;
        int n = can.size();
        // sort(can.begin(), can.end());
        for (int i = 0; i < n; i++){
            int num = can[i];
            // int pow = 0;
            int net = 0;
            while(num > 0){
                // num = num - (num % 2);
                len[net] += num % 2;
                ans = max(ans, len[net]);
                num = num / 2;
                net++;
            }
        }
        // for (auto x: len){
        //     cout<<x.first<<" : "<<x.second<<endl;
        // }
        return ans;
    }
};
