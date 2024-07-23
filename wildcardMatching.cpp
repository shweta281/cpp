class Solution {
public:
    bool asd( string s, string p, int i, int j, vector<vector<int>>&memo){
        if( i>=s.length() && j>=p.length()) return true;
        if(i>=s.length()){
            for ( j=j;j<p.length();j++){
                if(p[j]!='*') return false;
            }   
            return true;
        }
        if(j>=p.length()) return false;
        if(memo[i][j]!=-2) return memo[i][j];
        if(i<s.length() && s[i]==p[j]){
            return memo[i][j]= asd(s,p,i+1,j+1, memo);
        }
        else if(p[j]=='?'){
            return memo[i][j]= asd(s,p,i+1, j+1, memo);
        }
        else if(p[j]=='*') return memo[i][j]= asd(s, p, i, j+1, memo) || asd(s, p, i+1, j, memo) ;
        else
            return memo[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>memo(s.length(), vector<int>(p.length(),-2));
        return asd(s, p, 0, 0, memo);
    }
};
