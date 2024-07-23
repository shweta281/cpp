class Solution {
public:

    int asd(string &s, int i, int j, vector<vector<int>>&mem ){
        if(i>=j) return 0;
        if(mem[i][j]!=-1) return mem[i][j];
        if(s[i]==s[j]){
            return mem[i][j] = asd(s, i+1, j-1, mem);
        }
        else{
            return mem[i][j] = min(asd(s, i+1, j, mem)+1, asd(s, i, j-1, mem)+1);
        }
    }

    int minInsertions(string s) {
        vector<vector<int>>mem(s.length(), vector<int>(s.length(), -1));
        return asd(s, 0, s.length()-1, mem);
    }
};
