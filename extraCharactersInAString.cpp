class Solution {
public:

    int helper(int n, int i, int j, string&s, set<string>&dict, vector<vector<int>>&mem){
        if(i>=n && j>n){
            return 0;
        }
        if(j>n){
            return 50;
        }
        if(i>=n){
            return 0;
        }
        if(mem[i][j-1]!=-1){
            return mem[i][j-1];
        }
        string word=s.substr(i, j-i);
        cout<<word<<endl;
        if(dict.find(word)!=dict.end()){
            return mem[i][j-1] = min(helper(n, j, j+1, s, dict, mem) ,
            helper(n, i, j+1, s, dict, mem));
        } else {
            return mem[i][j-1] = min( helper(n, i, j+1, s, dict, mem), 
            helper(n, j, j+1, s, dict, mem)+(j-i));
        }
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        set<string>dict(dictionary.begin(), dictionary.end());
        vector<vector<int>>mem(n, vector<int>(n,-1));
        return helper(n, 0, 1, s, dict, mem);
    }
};
