class Solution {
public:
    bool asd(string s,string p, int i, int j, vector<vector<int>>&memo){
        if(i>=s.length() && j>=p.length()) return true;
        if(i>=s.length() && j<p.length()){ 
            j++;
            // cout<<j<<endl;
            while(j<p.length()){
                if(p[j]!='*') return false;
                j+=2;
            }
            // cout<<(p.length()+1)<<endl;
            if(j==p.length() && p[p.length()-1]!='*'){
                return false;
            }
            return true;
        }
        if(i>=s.length() || j>=p.length()) return false;
        if(memo[i][j]!=-1) return memo[i][j];
        // cout<<i<<" "<<j<<endl;
        if(s[i]==p[j]){
            if(j+1<p.length()){
                if(p[j+1]=='*'){ 
                    return memo[i][j]= asd(s,p,i+1,j, memo) || asd(s,p,i,j+2, memo);
                }
                else return memo[i][j]= asd(s,p,i+1,j+1, memo);
            }
            else{
                return memo[i][j]= asd(s,p,i+1,j+1, memo);
            }
        }
        else{
            if(p[j]=='.'){
                if(j+1<p.length()){
                    if(p[j+1]=='*'){ 
                        // cout<<"here"<<" "<<i<<" "<<j<<endl;
                        return memo[i][j]= asd(s,p,i+1,j, memo) || asd(s,p,i,j+2, memo);
                    }
                    else return memo[i][j]= asd(s,p,i+1,j+1, memo);
                }
                else{
                    return memo[i][j]= asd(s,p,i+1,j+1, memo);
                }
            }
            else{
                if(j+1<p.length()){
                    if(p[j+1]=='*') return memo[i][j]= asd(s,p,i,j+2, memo);
                    else return memo[i][j]= false;
                }
                else{
                    return memo[i][j]= false;
                }
            }
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>memo(s.length(),vector<int>(p.length(),-1));
        return asd(s,p,0,0, memo);
    }
};
