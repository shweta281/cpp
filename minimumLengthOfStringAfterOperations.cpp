class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>m;
        for (int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int ans=0;
        for (auto x:m){
            if(x.second%2!=0){
                    ans+=1;
                }
            else{
                    ans+=2;
                }
        }
        return ans;
    }
};
