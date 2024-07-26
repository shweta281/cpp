class Solution {
public:
    bool ispalindrom(string &s, int i, int j){
        for (int k=0;k<j/2;k++){
            if(s[i+k]!=s[i+j-k-1]) return false;
        }
        return true;
    }
    int asd( string &s, int i, vector<int>&mem){
        if(i>=s.length()) return 0;
        if(mem[i]!=-1) return mem[i];
        int ans=2001;
        for (int k=i; k<s.length(); k++){
            if(ispalindrom(s,i,k-i+1)){
                ans=min(ans, asd(s, k+1, mem)+1);
            }
        }
        return mem[i]=ans;
    }
    int minCut(string s) {
        vector<int>mem(s.length(),-1);
        return asd(s, 0, mem)-1;
    }
};
