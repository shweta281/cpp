class Solution {
public:// d: 1, v: 1,  
    int lengthOfLongestSubstring(string s) {
        int j=0;
        unordered_map<char, int>m;
        int kmax=0;
        for (int i=0;i<s.length();i++){
            if(m[s[i]]>=1){
                while(m[s[i]]>=1){
                    // cout<<m[s[j]]<<endl;
                    m[s[j]]--;
                    j++;
                }
            }
            m[s[i]]++;
            // cout<<j<<" "<<s[i]<<endl;
            kmax=max(kmax, i-j+1);
        }
        return kmax;
    }
};
