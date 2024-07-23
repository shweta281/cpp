class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int>m;
        int i=0;
        int ans=0;
        for (int j=0;j<s.length();j++){
            if(m.size()==3){
                while(i<j && m[s[i]]>1){
                    m[s[i]]--;
                    i++;
                }
                ans+=(i+1);
            }
            m[s[j]]++;
        }
        while(i<s.length() && m[s[i]]>1){
                    m[s[i]]--;
                    i++;
                }
        if(m.size()==3)
        ans+=(i+1);
        return ans;
        // return 0;
    }
};
