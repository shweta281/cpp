class Solution {
public:
//1010
//0111
//1101
//100
//011
//
    int minBitFlips(int start, int goal) {
        int temp=start^goal;
       string a=bitset<32>(temp).to_string();
       int ans=0;
       for (int i=0; i<32; i++){
        ans+=a[i]-'0';
       }
        return ans;
    }
};
