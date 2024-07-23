class Solution {
public:
    string longestPalindrome(string s) {
        int ans=0, mr=0, ml=0;
        for (int i=0; i<s.length(); i++){
            int left=i;
            int right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            if(ans<right-left+1){
                ans=right-left+1;
                mr=right-1;
                ml=left+1;
            }
        }
        for (int i=0; i<s.length(); i++){
            int left=i;
            int right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            if(ans<right-left+1){
                ans=right-left+1;
                mr=right-1;
                ml=left+1;
            }
        }
        cout<<ans<<" "<<mr<<" "<<ml;
        return s.substr(ml, mr-ml+1);
    }
};
