class Solution {
public:
    bool helper(unordered_set<int>& stones, int prev, int curr, int last, 
                    map<pair<long long, long long>, int>& mem) {
        if (curr > last) {
            return false;
        }
        if (curr == last) {
            return true;
        }
        if(mem.find({prev, curr}) != mem.end()){
            return mem[{prev, curr}];
        }
        bool ans = false;
        cout << prev << " " << curr << endl;
        //
        for (int i = prev - 1; i <= prev + 1; i++) {
            int goTo = curr + i;
            if (goTo <= curr || goTo > last) {
                continue;
            }
            if (goTo == last) {
                return mem[{prev, curr}]=true;
            }
            if (stones.find(goTo) != stones.end()) {
                ans = ans || helper(stones, i, goTo, last, mem);
            }
        }
        return mem[{prev, curr}]=ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_set<int> s(stones.begin(), stones.end());
        int n = stones.size();
        map<pair<long long, long long>, int> mem; 
        return helper(s, 0, 0, stones[n - 1], mem);
    }
};
