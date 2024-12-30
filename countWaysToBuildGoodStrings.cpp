class Solution {
public:
// 0 0 0 
    int helper(int l, int h, int z, int o, int len, vector<int>& mem){
        if(len > h){
            return 0;
        }
        if(mem[len] != -1){
            return mem[len];
        }
        if(len >= l && len <= h){
            return mem[len] = (helper(l,h,z,o, len+z, mem)%1000000007 + 
            helper(l,h,z,o,len+o, mem)%1000000007 + 1)%1000000007;
        } else{
            return mem[len] = (helper(l,h,z,o, len+z, mem)%1000000007 + 
            helper(l,h,z,o,len+o, mem)%1000000007)%1000000007;
        }
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> mem(high + 1, -1);
        return helper(low, high, zero, one, 0, mem);
    }
};
