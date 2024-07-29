class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator () (const pair<T1,T2> &p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;  
        }
    };

    int asd(vector<int>&cuts, int l, int r, unordered_map<pair<int,int>, int, pair_hash>&mem){
        if(l>=r) return 0;
        if(mem.find(make_pair(l,r))!=mem.end()) return mem[make_pair(l,r)];
        int ans=INT_MAX;
        for (int i=0; i<cuts.size(); i++){
            if(cuts[i]>l && cuts[i]<r){
                ans=min(ans, asd(cuts, l, cuts[i], mem)+
                asd(cuts, cuts[i], r, mem)+(r-l));
            }
        }
        if(ans==INT_MAX) ans=0;
        return mem[make_pair(l,r)]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        unordered_map<pair<int, int>, int, pair_hash>mem;
        return asd( cuts, 0, n, mem);
    }
};
