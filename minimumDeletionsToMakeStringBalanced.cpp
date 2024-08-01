class Solution {
public:
    int helper(string &s, int i, int c, vector<vector<int>>&cache){
        if(i>=s.length()) return 0;
        if(cache[i][c]!=-1) return cache[i][c];
        if(c==0){
            if(s[i]=='b'){
                return cache[i][c] =min( 1+helper(s, i+1, 0, cache), 
                helper(s, i+1, 1 , cache));
            }
            else{
                return cache[i][c]=helper(s, i+1, 0, cache);
            }
        }
        else{
            if(s[i]=='a')
                return cache[i][c]=helper(s, i+1, 1, cache)+1;
            else{
                return cache[i][c]=helper(s, i+1, 1, cache);
            }
        }
    }
    int minimumDeletions(string s) {
        vector<vector<int>>cache(s.length(), vector<int>(2, -1));
        return helper(s, 0, 0, cache);
    }
};
